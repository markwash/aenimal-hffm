#include <cxxtest/TestSuite.h>

extern "C" {
#include "hffm_solution.h"
#include "hffm_solution_private.h"
#include "hffm_mock_solution.h"
}


#include <iostream>
using namespace std;

class SolutionTestSuite : public CxxTest::TestSuite 
{
	hffm_solution_t *sol;
	mock_solution_t *msol;

public:
	void setUp()
	{
		msol = mock_solution_new();
		sol = (hffm_solution_t *) msol;
	}
	void tearDown()
	{
		mock_solution_really_free(msol);
	}
	void test_free()
	{
		TS_ASSERT_EQUALS(msol->times_free_called, 0);
		hffm_solution_free(sol);
		TS_ASSERT_EQUALS(msol->times_free_called, 1);
	}

};

