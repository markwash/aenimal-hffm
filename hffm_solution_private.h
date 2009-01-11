#ifndef hffm_solution_private_h
#define hffm_solution_private_h

#include "hffm_solution.h"

struct hffm_solution_methods;
typedef struct hffm_solution_methods hffm_solution_methods_t;

typedef void (*hffm_solution_free_fn)(hffm_solution_t *);

struct hffm_solution_methods {
	hffm_solution_free_fn free;
};

struct hffm_solution {
	hffm_solution_methods_t *methods;
};
	
#endif
