'use client';

import React from 'react';

export default function UniverseBanner() {
  const basePath = process.env.NEXT_PUBLIC_BASE_PATH || '';

  return (
    <section className="relative overflow-hidden py-16 border-b border-slate-800 bg-slate-950">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <div className="relative rounded-3xl overflow-hidden border border-slate-800 shadow-2xl group">
          {/* Panoramic Image */}
          <img
            src={`${basePath}/images/universes-art.jpg`}
            alt="40 Universes Colliding: Fantasy and Sci-Fi Realms of namgen"
            className="w-full h-72 sm:h-96 lg:h-[420px] object-cover object-center group-hover:scale-105 transition-transform duration-700"
            loading="lazy"
          />

          {/* Dark gradient overlay for text readability */}
          <div className="absolute inset-0 bg-gradient-to-t from-slate-950 via-slate-950/60 to-transparent flex flex-col justify-end p-6 sm:p-10 lg:p-12">
            <div className="inline-flex items-center gap-2 px-3 py-1 rounded-full text-xs font-semibold bg-emerald-500/20 text-emerald-300 border border-emerald-500/40 w-fit mb-3 backdrop-blur-sm">
              <span>907 Modules Across 40 Factions & Real-World Cultures</span>
            </div>
            <h3 className="text-2xl sm:text-3xl lg:text-4xl font-extrabold text-white max-w-2xl leading-tight">
              Where Ancient Lore Meets Distant Galaxies
            </h3>
            <p className="mt-2 text-xs sm:text-sm lg:text-base text-slate-300 max-w-2xl">
              From Tolkien's Middle-earth, D&D multiverses, Warhammer 40,000, and Star Wars to ancient Norse dynasties, cyberpunk firearms, and narrative planet descriptions.
            </p>
          </div>
        </div>
      </div>
    </section>
  );
}
