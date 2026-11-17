const { contextBridge, ipcRenderer } = require('electron');

contextBridge.exposeInMainWorld('namgenDesktop', {
  platform: process.platform,
  isDesktop: true,
  versions: {
    electron: process.versions.electron,
    chrome: process.versions.chrome,
    node: process.versions.node,
  },
});
