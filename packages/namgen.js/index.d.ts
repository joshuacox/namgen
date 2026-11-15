/**
 * TypeScript definitions for namgen.js
 */

export interface GeneratorDescriptor {
  id: string;
  flag: string;
  category: string;
  categoryName: string;
  name: string;
  aliases: string[];
  description: string;
  samples: string[];
}

export interface CategoryDescriptor {
  id: string;
  name: string;
  description: string;
  count: number;
}

export interface NamgenOptions {
  seed?: number | string;
  unique?: boolean;
  type?: number;
  matchRegex?: string;
  alliterate?: boolean;
  syllables?: number;
  minLen?: number;
  maxLen?: number;
  withLore?: boolean;
}

export interface CombinatorOptions extends NamgenOptions {
  count?: number;
  separator?: string;
  nullSeparator?: boolean;
  casing?: 'normal' | 'cap' | 'camel';
  exclude?: string;
}

export declare const generators: GeneratorDescriptor[];
export declare const categories: CategoryDescriptor[];
export declare const words: { adjectives: string[]; nouns: string[] };

export function getGenerator(idOrFlag: string): GeneratorDescriptor | null;
export function hasGenerator(idOrFlag: string): boolean;
export function searchGenerators(query?: string, category?: string, limit?: number): GeneratorDescriptor[];
export function getGeneratorsByCategory(categoryId: string): GeneratorDescriptor[];

export function createSeededRandom(seed?: number | string): () => number;
export function toSlug(str: string): string;
export function formatOutput(names: string[], format?: 'plain' | 'json' | 'csv' | 'slug'): string;
export function countSyllables(name: string): number;
export function isAlliterative(name: string): boolean;
export function formatWithLore(name: string, rng?: () => number): string;
export function capitalizeProperName(name: string): string;

export function generateCombinations(options?: CombinatorOptions): string[];
export function executeGeneratorFn(fn: (type?: number) => string, count?: number, options?: NamgenOptions): string[];
export function composeGenerators(fns: Array<(type?: number) => string>, template?: string, count?: number, options?: NamgenOptions): string[];
