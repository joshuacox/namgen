'use client';

import React from 'react';
import Navbar from '../components/Navbar';
import Hero from '../components/Hero';
import Playground from '../components/Playground';
import Features from '../components/Features';
import Installation from '../components/Installation';
import OptionsReference from '../components/OptionsReference';
import GeneratorExplorer from '../components/GeneratorExplorer';
import Architecture from '../components/Architecture';
import Footer from '../components/Footer';

export default function HomePage() {
  return (
    <div className="flex flex-col min-h-screen">
      <Navbar />
      <main className="flex-grow">
        <Hero />
        <Playground />
        <Features />
        <Installation />
        <OptionsReference />
        <GeneratorExplorer />
        <Architecture />
      </main>
      <Footer />
    </div>
  );
}
