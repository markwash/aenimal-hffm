#include "hffm_rand.h"

#include <stdint.h>
#include <sys/types.h>
#include <sys/time.h>

static uint32_t Q[4096],c=362436;

void hffm_rand_init() {
	int i = 0; 
	uint32_t x = 0;
	for (i = 0; i < 4096; i++) {
		Q[i] = x;
		x=69069*x+362437;
	}
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

