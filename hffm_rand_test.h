#include <cxxtest/TestSuite.h>
#include <stdint.h>

extern "C" {
#include "hffm_rand.h"
}


#include <iostream>
using namespace std;

class RandTestSuite : public CxxTest::TestSuite 
{

public:
	void setUp()
	{
		hffm_rand_init();
	}
	void tearDown()
	{
	}
	void test_hffm_rand_uint32()
	{
		uint32_t r = hffm_rand_uint32();
		TS_ASSERT_LESS_THAN_EQUALS(0, r);
		TS_ASSERT_LESS_THAN_EQUALS(r, 0xffffffff);
	}
	void test_hffm_one_bit_completeness()
	{
		uint32_t masks[32];
		uint32_t counts[32][2];
		int i, j;
		for (i = 0; i < 32; i++) {
			masks[i] = 1 << i;
			for (j = 0; j < 2; j++) {
				counts[i][j] = 0;
			}
		}
		uint32_t r;
		for (i = 0; i < 1000; i++) {
			r = hffm_rand_uint32();
			for (j = 0; j < 32; j++) {
				counts[j][(r & masks[j]) / masks[j]] += 1;
			}
		}
		for (i = 0; i < 32; i++) {
			for (j = 0; j < 2; j++) {
				TS_ASSERT_LESS_THAN(0, counts[i][j]);
			}
		}
	}
	void test_rand_compare()
	{
		uint64_t above = 0, below = 0;
		uint32_t r, p;
		r = hffm_rand_uint32();
		int i;
		for (i = 0; i < 10000; i++) {
			p = r;
			r = hffm_rand_uint32();
			if (r >= p) {
				above += p;
			} else {
				below += 0xffffffff - p;
			}
		}
		double da, db;
		da = above / 10000.0 / 0xffffffff;
		db = below / 10000.0 / 0xffffffff;
		TS_ASSERT_DELTA(da, db, 0.01);
	}
};

