//! # namgen
//!
//! Rust client bindings for `namgen`, the ultra-fast fantasy and sci-fi name generator library.
//!
//! ## Example
//! ```no_run
//! use namgen::{generate, markov};
//!
//! let names = generate("fantasy-elves", 5, 42).unwrap();
//! for name in names {
//!     println!("Hero: {}", name);
//! }
//!
//! let novel_names = markov("fantasy-dragons", 3, 3, 42).unwrap();
//! for name in novel_names {
//!     println!("Synthesized Dragon: {}", name);
//! }
//! ```

use std::ffi::{CStr, CString};
use std::os::raw::{c_char, c_int, c_uint};

extern "C" {
    fn namgen_c_generate(
        generator_flag: *const c_char,
        count: c_int,
        seed: c_uint,
        out_buf: *mut c_char,
        max_buf_len: c_int,
    ) -> c_int;

    fn namgen_c_markov(
        generator_flag: *const c_char,
        count: c_int,
        order: c_int,
        seed: c_uint,
        out_buf: *mut c_char,
        max_buf_len: c_int,
    ) -> c_int;

    fn namgen_c_generator_count() -> c_int;
    fn namgen_c_generator_flag(index: c_int) -> *const c_char;
    fn namgen_c_generator_desc(index: c_int) -> *const c_char;
}

/// Generate names from a specialized generator.
///
/// # Arguments
/// * `generator` - Name or flag of the generator (e.g. "fantasy-elves" or "--fantasy-dragons")
/// * `count` - Number of names to generate
/// * `seed` - Deterministic seed (0 for pseudo-random)
pub fn generate(generator: &str, count: usize, seed: u32) -> Result<Vec<String>, String> {
    if count == 0 {
        return Ok(Vec::new());
    }

    let c_gen = CString::new(generator).map_err(|e| e.to_string())?;
    let buf_size = 4096.max(count * 128);
    let mut buffer: Vec<u8> = vec![0; buf_size];

    let res = unsafe {
        namgen_c_generate(
            c_gen.as_ptr(),
            count as c_int,
            seed as c_uint,
            buffer.as_mut_ptr() as *mut c_char,
            buf_size as c_int,
        )
    };

    if res < 0 {
        return Err(format!("namgen error code: {}", res));
    }

    let c_str = unsafe { CStr::from_ptr(buffer.as_ptr() as *const c_char) };
    let string_val = c_str.to_string_lossy();
    Ok(string_val.lines().map(|s| s.to_string()).collect())
}

/// Synthesize novel names using a Markov n-gram character model trained on a generator.
pub fn markov(generator: &str, count: usize, order: u32, seed: u32) -> Result<Vec<String>, String> {
    if count == 0 {
        return Ok(Vec::new());
    }

    let c_gen = CString::new(generator).map_err(|e| e.to_string())?;
    let buf_size = 4096.max(count * 128);
    let mut buffer: Vec<u8> = vec![0; buf_size];

    let res = unsafe {
        namgen_c_markov(
            c_gen.as_ptr(),
            count as c_int,
            order as c_int,
            seed as c_uint,
            buffer.as_mut_ptr() as *mut c_char,
            buf_size as c_int,
        )
    };

    if res < 0 {
        return Err(format!("namgen markov error code: {}", res));
    }

    let c_str = unsafe { CStr::from_ptr(buffer.as_ptr() as *const c_char) };
    let string_val = c_str.to_string_lossy();
    Ok(string_val.lines().map(|s| s.to_string()).collect())
}

/// Retrieve the count of registered generators.
pub fn generator_count() -> usize {
    unsafe { namgen_c_generator_count() as usize }
}
