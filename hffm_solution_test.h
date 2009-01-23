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
	void test_vary()
	{
		TS_ASSERT_EQUALS(msol->times_vary_called, 0);
		hffm_solution_vary(sol, 1.0);
		TS_ASSERT_EQUALS(msol->times_vary_called, 1);
		TS_ASSERT_EQUALS(msol->last_vary_amt, 1.0);
		hffm_solution_vary(sol, 0.25);
		TS_ASSERT_EQUALS(msol->times_vary_called, 2);
		TS_ASSERT_EQUALS(msol->last_vary_amt, 0.25);
	}
	void test_error()
	{
		msol->error = 1.0;
		TS_ASSERT_EQUALS(hffm_solution_error(sol), 1.0);
		msol->error = 10.0;
		TS_ASSERT_EQUALS(hffm_solution_error(sol), 10.0);
	}
	void test_copy()
	{
		TS_ASSERT_EQUALS(msol->generation, 0);
		hffm_solution_t *sol2 = hffm_solution_copy(sol);
		mock_solution_t *msol2 = (mock_solution_t *) sol2;
		TS_ASSERT_EQUALS(msol->generation, 0);
		TS_ASSERT_EQUALS(msol2->generation, 1);
		mock_solution_really_free(msol2);
	}
	void test_accepted()
	{
		TS_ASSERT_EQUALS(msol->times_accepted_called, 0);
		hffm_solution_accepted(sol);
		TS_ASSERT_EQUALS(msol->times_accepted_called, 1);
	}
};

