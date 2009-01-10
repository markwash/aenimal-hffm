
struct hffm_solution;
typedef struct hffm_solution hffm_solution_t;

double hffm_solution_error(hffm_solution_t *sol);
void hffm_solution_vary(hffm_solution_t *sol, double amount);
hffm_solution_t *hffm_solution_copy(hffm_solution_t *sol);
