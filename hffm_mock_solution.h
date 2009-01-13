#ifndef hffm_mock_solution_h
#define hffm_mock_solution_h

#include "hffm_solution_private.h"

struct mock_solution;
typedef struct mock_solution mock_solution_t;

struct mock_solution {
	hffm_solution_t base;
	
	int generation;
	int times_free_called;
	int times_vary_called;
	double last_vary_amt;
	double error;
};

mock_solution_t *mock_solution_new();
void mock_solution_really_free(mock_solution_t *sol);



#endif
