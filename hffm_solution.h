#ifndef hffm_solution_h
#define hffm_solution_h

struct hffm_solution;
typedef struct hffm_solution hffm_solution_t;

void hffm_solution_free(hffm_solution_t *sol);
double hffm_solution_error(hffm_solution_t *sol);
void hffm_solution_vary(hffm_solution_t *sol, double amount);
hffm_solution_t *hffm_solution_copy(hffm_solution_t *sol);

#endif
