import './globals.css';

export const metadata = {
  title: 'namgen DM Vault — Private Local D&D Dungeon Master Screen',
  description:
    'Private, offline-first D&D Dungeon Master command center powered by namgen.js (917 procedural generators, NPC forge, initiative tracker, taverns, dungeons, loot, and local Markdown vault).',
};

export default function RootLayout({ children }) {
  return (
    <html lang="en" className="dark">
      <head>
        <meta charSet="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
        <link
          rel="icon"
          href="data:image/svg+xml,<svg xmlns=%22http://www.w3.org/2000/svg%22 viewBox=%220 0 100 100%22><text y=%22.9em%22 font-size=%2290%22>🐉</text></svg>"
        />
      </head>
      <body className="antialiased selection:bg-amber-500/30 selection:text-amber-200">
        {children}
      </body>
    </html>
  );
}
