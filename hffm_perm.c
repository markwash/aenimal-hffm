#include "hffm_perm.h"

#include <stdlib.h>
#include <assert.h>

void hffm_perm_init(uint32_t *perm, uint32_t size) {
	uint32_t i;
	assert(perm != NULL);
	for (i = 0; i < size; i++) {
		perm[i] = i;
	}
}
void hffm_perm_next(uint32_t *perm, uint32_t size, uint32_t max) {
	assert(size <= max);
	uint32_t i, pos;
	for (i = 0; i < size; i++) {
		pos = size - i - 1;
		if (perm[pos] < (max - i - 1)) {
			perm[pos]++;
			break;
		}
	}
	if (i == size) {
		for (i = 0; i < size; i++) {
			perm[i] = i;
		}
		return;
	}
	for (i = 1; i < size - pos; i++) {
			perm[i + pos] = perm[pos] + i;
	}
	return;
}
