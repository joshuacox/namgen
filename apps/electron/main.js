const { app, BrowserWindow, shell, ipcMain, Menu } = require('electron');
const path = require('path');
const http = require('http');
const fs = require('fs');
const Module = require('module');

// Intercept module resolution for Next.js internal runtime requires
// When Next.js runs from extracted resources outside of app.asar,
// its server webpack runtime requires 'next/dist/...', which needs to resolve
// into the bundled node_modules inside app.asar.
function setupModuleResolution() {
  const origResolve = Module._resolveFilename;
  let nextDir = null;
  let reactDir = null;
  let reactDomDir = null;

  try {
    nextDir = path.dirname(require.resolve('next/package.json'));
  } catch {}
  try {
    reactDir = path.dirname(require.resolve('react/package.json'));
  } catch {}
  try {
    reactDomDir = path.dirname(require.resolve('react-dom/package.json'));
  } catch {}

  Module._resolveFilename = function (request, parent, isMain, options) {
    if (nextDir && request.startsWith('next/')) {
      const sub = request.slice('next/'.length);
      const target = path.join(nextDir, sub);
      try {
        return origResolve.call(this, target, parent, isMain, options);
      } catch {}
    }
    if (reactDir && (request === 'react' || request.startsWith('react/'))) {
      const sub = request === 'react' ? 'index.js' : request.slice('react/'.length);
      const target = path.join(reactDir, sub);
      try {
        return origResolve.call(this, target, parent, isMain, options);
      } catch {}
    }
    if (reactDomDir && (request === 'react-dom' || request.startsWith('react-dom/'))) {
      const sub = request === 'react-dom' ? 'index.js' : request.slice('react-dom/'.length);
      const target = path.join(reactDomDir, sub);
      try {
        return origResolve.call(this, target, parent, isMain, options);
      } catch {}
    }
    return origResolve.call(this, request, parent, isMain, options);
  };
}

setupModuleResolution();

const isDev = process.env.NODE_ENV === 'development' || !app.isPackaged;
let mainWindow = null;
let serverProcess = null;
let serverPort = null;

// Determine paths for data directory and binary
function setupEnvironment() {
  const userDataPath = app.getPath('userData');
  const dataDir = path.join(userDataPath, 'namgen-data');
  process.env.NAMGEN_DM_DATA_DIR = dataDir;

  // Detect bundled binary or development binary
  const binaryName = process.platform === 'win32' ? 'namgen.exe' : 'namgen';
  const candidateBinaries = [
    // Unpacked extraResources location in production
    path.join(process.resourcesPath || '', 'bin', binaryName),
    path.join(process.resourcesPath || '', binaryName),
    // Development fallback
    path.join(app.getAppPath(), '..', '..', binaryName),
    path.join(process.cwd(), binaryName),
  ];

  for (const candidate of candidateBinaries) {
    try {
      if (fs.existsSync(candidate)) {
        process.env.NAMGEN_BIN_PATH = candidate;
        break;
      }
    } catch {}
  }
}

function findFreePort(startPort, endPort) {
  return new Promise((resolve, reject) => {
    let port = startPort;
    function tryPort() {
      if (port > endPort) {
        return reject(new Error(`No free port found between ${startPort} and ${endPort}`));
      }
      const tester = http.createServer();
      tester.once('error', (err) => {
        if (err.code === 'EADDRINUSE') {
          port++;
          tryPort();
        } else {
          reject(err);
        }
      });
      tester.once('listening', () => {
        tester.close(() => resolve(port));
      });
      tester.listen(port, '127.0.0.1');
    }
    tryPort();
  });
}

async function startNextServer() {
  const port = await findFreePort(38000, 39999);
  serverPort = port;

  let webDir;
  if (app.isPackaged) {
    webDir = path.join(process.resourcesPath, 'web');
  } else {
    webDir = path.resolve(__dirname, '..', 'web');
  }

  // Set production environment for Next.js in desktop mode
  process.env.NODE_ENV = 'production';
  process.env.PORT = String(port);
  process.env.HOSTNAME = '127.0.0.1';

  // Import Next.js programmatically
  const next = require('next');
  const nextApp = next({
    dev: false,
    dir: webDir,
    hostname: '127.0.0.1',
    port: port,
  });

  const handle = nextApp.getRequestHandler();
  await nextApp.prepare();

  const server = http.createServer((req, res) => {
    handle(req, res);
  });

  await new Promise((resolve, reject) => {
    server.listen(port, '127.0.0.1', (err) => {
      if (err) return reject(err);
      resolve();
    });
  });

  serverProcess = server;
  console.log(`[namgen-electron] Next.js server running on http://127.0.0.1:${port}`);
  return port;
}

function createWindow(port) {
  mainWindow = new BrowserWindow({
    width: 1380,
    height: 920,
    minWidth: 1024,
    minHeight: 700,
    title: 'namgen DM Command Center',
    backgroundColor: '#020617',
    icon: path.join(__dirname, 'assets', 'icon.png'),
    webPreferences: {
      preload: path.join(__dirname, 'preload.js'),
      nodeIntegration: false,
      contextIsolation: true,
      sandbox: false,
    },
    show: false,
  });

  const startUrl = `http://127.0.0.1:${port}`;
  mainWindow.loadURL(startUrl);

  mainWindow.once('ready-to-show', () => {
    mainWindow.show();
  });

  // Handle external links safely via default browser
  mainWindow.webContents.setWindowOpenHandler(({ url }) => {
    if (url.startsWith('http:') || url.startsWith('https:')) {
      shell.openExternal(url);
    }
    return { action: 'deny' };
  });

  mainWindow.on('closed', () => {
    mainWindow = null;
  });

  buildAppMenu();
}

function buildAppMenu() {
  const isMac = process.platform === 'darwin';
  const template = [
    ...(isMac
      ? [
          {
            label: app.name,
            submenu: [
              { role: 'about' },
              { type: 'separator' },
              { role: 'services' },
              { type: 'separator' },
              { role: 'hide' },
              { role: 'hideOthers' },
              { role: 'unhide' },
              { type: 'separator' },
              { role: 'quit' },
            ],
          },
        ]
      : []),
    {
      label: 'File',
      submenu: [
        {
          label: 'Open Data Directory',
          click: () => {
            if (process.env.NAMGEN_DM_DATA_DIR) {
              shell.openPath(process.env.NAMGEN_DM_DATA_DIR);
            }
          },
        },
        { type: 'separator' },
        isMac ? { role: 'close' } : { role: 'quit' },
      ],
    },
    {
      label: 'View',
      submenu: [
        { role: 'reload' },
        { role: 'forceReload' },
        { role: 'toggleDevTools' },
        { type: 'separator' },
        { role: 'resetZoom' },
        { role: 'zoomIn' },
        { role: 'zoomOut' },
        { type: 'separator' },
        { role: 'togglefullscreen' },
      ],
    },
    {
      label: 'Help',
      submenu: [
        {
          label: 'namgen GitHub Repository',
          click: () => shell.openExternal('https://github.com/joshuacox/namgen'),
        },
        {
          label: 'Report Issue',
          click: () => shell.openExternal('https://github.com/joshuacox/namgen/issues'),
        },
      ],
    },
  ];

  const menu = Menu.buildFromTemplate(template);
  Menu.setApplicationMenu(menu);
}

// Single instance lock
const gotTheLock = app.requestSingleInstanceLock();

if (!gotTheLock) {
  app.quit();
} else {
  app.on('second-instance', () => {
    if (mainWindow) {
      if (mainWindow.isMinimized()) mainWindow.restore();
      mainWindow.focus();
    }
  });

  app.whenReady().then(async () => {
    setupEnvironment();
    try {
      const port = await startNextServer();
      createWindow(port);

      app.on('activate', () => {
        if (BrowserWindow.getAllWindows().length === 0) {
          createWindow(serverPort || port);
        }
      });
    } catch (err) {
      console.error('Failed to start application:', err);
      app.quit();
    }
  });

  app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') {
      app.quit();
    }
  });

  app.on('will-quit', () => {
    if (serverProcess) {
      try {
        serverProcess.close();
      } catch {}
    }
  });
}
