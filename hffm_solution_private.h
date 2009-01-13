#ifndef hffm_solution_private_h
#define hffm_solution_private_h

#include "hffm_solution.h"

struct hffm_solution_methods;
typedef struct hffm_solution_methods hffm_solution_methods_t;

typedef void (*hffm_solution_free_fn)(hffm_solution_t *);
typedef void (*hffm_solution_vary_fn)(hffm_solution_t *, double);
typedef double (*hffm_solution_error_fn)(hffm_solution_t *);
typedef hffm_solution_t *(*hffm_solution_copy_fn)(hffm_solution_t *);

struct hffm_solution_methods {
	hffm_solution_free_fn free;
	hffm_solution_vary_fn vary;
	hffm_solution_error_fn error;
	hffm_solution_copy_fn copy;
};

struct hffm_solution {
	hffm_solution_methods_t *methods;
};
	
#endif
