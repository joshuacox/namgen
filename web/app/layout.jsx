import './globals.css';

export const metadata = {
  title: 'namgen — Ultra-Fast C++17 Procedural Name Generator & 907 Modules',
  description: 'A high-performance C++17 name generator combining adjectives and nouns with 907 zero-allocation procedural generators spanning 40 fantasy, sci-fi, and real-world universes.',
  keywords: 'name generator, fantasy names, sci-fi names, procedural generation, C++17, zero allocation, CLI tool, open source',
  authors: [{ name: 'Joshua Cox' }],
};

export default function RootLayout({ children }) {
  return (
    <html lang="en" className="scroll-smooth">
      <head>
        <meta charSet="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
        <link rel="manifest" href="/manifest.json" />
        <meta name="theme-color" content="#10b981" />
        <link rel="icon" href="data:image/svg+xml,<svg xmlns=%22http://www.w3.org/2000/svg%22 viewBox=%220 0 100 100%22><text y=%22.9em%22 font-size=%2290%22>⚡</text></svg>" />
      </head>
      <body className="min-h-screen bg-slate-950 text-slate-100 antialiased selection:bg-emerald-500/30 selection:text-emerald-300">
        {children}
        <script
          dangerouslySetInnerHTML={{
            __html: `
              if ('serviceWorker' in navigator && window.location.protocol.startsWith('http')) {
                window.addEventListener('load', () => {
                  navigator.serviceWorker.register('/sw.js').catch(() => {});
                });
              }
            `,
          }}
        />
      </body>
    </html>
  );
}
