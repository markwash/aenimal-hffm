#include "hffm_solution.h"
#include "hffm_solution_private.h"

void hffm_solution_free(hffm_solution_t *sol) {
	sol->methods->free(sol);
}
