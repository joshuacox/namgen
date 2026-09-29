/**
 * TypeScript definitions for namgen WebAssembly module
 */

export interface NamgenOptions {
  seed?: number;
  unique?: boolean;
}

export interface NamgenCLI {
  instance: any;
  /**
   * Check if a generator flag or alias exists.
   * @param flag Generator flag name (e.g. "--fantasy-dragons" or "fantasy-dragons")
   */
  hasGenerator(flag: string): boolean;

  /**
   * Generate names for a specific generator flag.
   * @param flag Generator flag name
   * @param count Number of names to generate (default: 1)
   * @param seed Optional random number generator seed
   */
  generate(flag: string, count?: number, seed?: number): string[];

  /**
   * Execute command-line arguments directly in WebAssembly C++ main().
   * @param args CLI argument array (e.g. ["--fantasy-dragons", "-c", "5", "--json"])
   */
  run(args: string[]): number;
}

/**
 * Initialize and load the namgen WebAssembly runtime.
 */
export function initNamgen(): Promise<NamgenCLI>;

/**
 * Underlying Emscripten module factory.
 */
export function createNamgen(options?: any): Promise<any>;
