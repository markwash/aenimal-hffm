#ifndef hffm_rand_h
#define hffm_rand_h

#include <sys/types.h>
#include <stdint.h>

size_t hffm_rand_seed_len();
void hffm_rand_set_seed(const void *seed);
const void *hffm_rand_get_seed();

void hffm_rand_seed_from_uint32(uint32_t seed);
void hffm_rand_seed_from_time();
void hffm_rand_seed_default();

uint32_t hffm_rand_uint32();
double hffm_rand_double();
uint32_t hffm_rand_range(uint32_t start, uint32_t len);


#endif
