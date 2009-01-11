#include "hffm_mock_solution.h"

#include <stdlib.h>

static void mock_solution_free(mock_solution_t *sol);

static hffm_solution_methods_t methods = {
	(hffm_solution_free_fn) mock_solution_free,
};

mock_solution_t *mock_solution_new() {
	mock_solution_t *sol;
	sol = malloc(sizeof(mock_solution_t));
	if (sol == NULL) {
		return NULL;
	}
	sol->base.methods = &methods;
	sol->times_free_called = 0;
	return sol;
}
void mock_solution_really_free(mock_solution_t *sol) {
	free(sol);
}

static void mock_solution_free(mock_solution_t *sol) {
	sol->times_free_called++;
}
