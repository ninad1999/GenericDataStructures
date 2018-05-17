#include "glist.h"
#include "gstack.h"
#include "gdsutils.h"

#include <stdio.h>

void quick_test_1()
{
	struct stack *sp = stack_create(are_equal_int, fprint_int);
	int X[] = {1, 2, 3, 5};

	stack_push(X + 0, sp);
	print_glist(stdout, sp->glp);

	stack_push(X + 1, sp);
	print_glist(stdout, sp->glp);

	int *x = (int *)stack_pop(sp);
	printf("Popped %d.\n", *x);

	stack_push(X + 2, sp);
	print_glist(stdout, sp->glp);

	stack_push(X + 3, sp);
	print_glist(stdout, sp->glp);

	stack_destroy(sp);
}

int main(int argc, char *argv[], char *envp[])
{
	quick_test_1();

	return 0;
}

