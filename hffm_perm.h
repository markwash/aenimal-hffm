#ifndef hffm_perm_h
#define hffm_perm_h

#include <stdint.h>

void hffm_perm_init(uint32_t *perm, uint32_t size);
void hffm_perm_next(uint32_t *perm, uint32_t size, uint32_t max);

#endif
