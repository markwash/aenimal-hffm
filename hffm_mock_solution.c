#include "hffm_mock_solution.h"

#include <stdlib.h>

static void mock_solution_free(mock_solution_t *sol);
static void mock_solution_vary(mock_solution_t *sol, double amount);
static double mock_solution_error(mock_solution_t *sol);
static void mock_solution_accepted(mock_solution_t *sol);
static mock_solution_t *mock_solution_copy(mock_solution_t *sol);

static hffm_solution_methods_t methods = {
	(hffm_solution_free_fn) mock_solution_free,
	(hffm_solution_vary_fn) mock_solution_vary,
	(hffm_solution_error_fn) mock_solution_error,
	(hffm_solution_accepted_fn) mock_solution_accepted,
	(hffm_solution_copy_fn) mock_solution_copy,
};

mock_solution_t *mock_solution_new() {
	mock_solution_t *sol;
	sol = malloc(sizeof(mock_solution_t));
	if (sol == NULL) {
		return NULL;
	}
	sol->base.methods = &methods;
	sol->generation = 0;
	sol->times_free_called = 0;
	sol->times_vary_called = 0;
	sol->times_accepted_called = 0;
	sol->last_vary_amt = 0.0;
	return sol;
}
void mock_solution_really_free(mock_solution_t *sol) {
	free(sol);
}

static void mock_solution_free(mock_solution_t *sol) {
	sol->times_free_called++;
}
static void mock_solution_vary(mock_solution_t *sol, double amount) {
	sol->times_vary_called++;
	sol->last_vary_amt = amount;
}
static double mock_solution_error(mock_solution_t *sol) {
	return sol->error;
}
static void mock_solution_accepted(mock_solution_t *sol) {
	sol->times_accepted_called++;
}
static mock_solution_t *mock_solution_copy(mock_solution_t *sol) {
	mock_solution_t *copy;
	copy = mock_solution_new();
	copy->generation = sol->generation + 1;
	return copy;
}
