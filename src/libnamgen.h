#ifndef LIBNAMGEN_H
#define LIBNAMGEN_H

#ifdef __cplusplus
extern "C" {
#endif

// Returns number of characters written into out_buf (newline separated if count > 1), or negative error code
int namgen_c_generate(const char* generator_flag, int count, unsigned int seed, char* out_buf, int max_buf_len);

// Markov generation
int namgen_c_markov(const char* generator_flag, int count, int order, unsigned int seed, char* out_buf, int max_buf_len);

// Generator introspection
int namgen_c_generator_count(void);
const char* namgen_c_generator_flag(int index);
const char* namgen_c_generator_desc(int index);

#ifdef __cplusplus
}
#endif

#endif // LIBNAMGEN_H
