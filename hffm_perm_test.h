#include <cxxtest/TestSuite.h>
#include <stdint.h>

extern "C" {
#include "hffm_perm.h"
}


#include <iostream>
using namespace std;

class PermTestSuite : public CxxTest::TestSuite 
{

	uint32_t perm[10];

public:
	void setUp()
	{
		hffm_perm_init(perm, 3);
	}
	void tearDown()
	{
	}
	void test_hffm_perm_init()
	{
		uint32_t i;
		for (i = 0; i < 3; i++) {
			TS_ASSERT_EQUALS(perm[i], i);
		}
	}
	void test_hffm_perm_next()
	{
		uint32_t i, j, k;
		for (i = 0; i < 5; i++) {
			for (j = i + 1; j < 5; j++) {
				for (k = j + 1; k < 5; k++) {
					TS_ASSERT_EQUALS(perm[0], i);
					TS_ASSERT_EQUALS(perm[1], j);
					TS_ASSERT_EQUALS(perm[2], k);
					hffm_perm_next(perm, 3, 5);
				}
			}
		}
	}
};

