#include "hffm_solution.h"
#include "hffm_solution_private.h"

void hffm_solution_free(hffm_solution_t *sol) {
	sol->methods->free(sol);
}
void hffm_solution_vary(hffm_solution_t *sol, double amount) {
	sol->methods->vary(sol, amount);
}
double hffm_solution_error(hffm_solution_t *sol) {
	return sol->methods->error(sol);
}
void hffm_solution_accepted(hffm_solution_t *sol) {
	sol->methods->accepted(sol);
}
hffm_solution_t *hffm_solution_copy(hffm_solution_t *sol) {
	return sol->methods->copy(sol);
}
