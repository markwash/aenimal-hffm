#include "hffm_rand.h"

#include <string.h>
#include <sys/time.h>

static uint32_t Q[4096],c=362436;
static size_t seed_len = 4096 * sizeof(uint32_t);

size_t hffm_rand_seed_len() {
	return seed_len;
}
void hffm_rand_set_seed(const void *seed) {
	memcpy((void *) &Q, seed, seed_len);
	return;
}
const void *hffm_rand_get_seed() {
	return (void *) &Q;
}
void hffm_rand_seed_from_uint32(uint32_t x) {
	int i = 0; 
	for (i = 0; i < 4096; i++) {
		Q[i] = x;
		x=69069*x+362437;
	}
}
void hffm_rand_seed_from_time() {
	hffm_rand_seed_from_uint32(time(NULL));
}
void hffm_rand_seed_default() {
	hffm_rand_seed_from_time();
}

uint32_t hffm_rand_uint32() {
	uint64_t t, a=18782LL;
	static uint32_t i=4095;
	uint32_t x,r=0xfffffffe;
	i=(i+1)&4095;
	t=a*Q[i]+c;
	c=(t>>32); x=t+c; if(x<c){x++;c++;}
	return(Q[i]=r-x);
}
uint32_t hffm_rand_range(uint32_t start, uint32_t len) {
	return start + hffm_rand_uint32() % len;
}
double hffm_rand_double() {
	return 1.0 * hffm_rand_uint32() / 0x100000000LL;
}
