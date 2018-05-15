#include <stdio.h>
#include <stdlib.h>

struct stack {
	struct glist *glp;
	bool (* g_are_equal)(void *, void *);
	int (* g_print)(FILE *, void *);
}

struct stack *stack_create(bool (* f)(void *, void *), int (* g)(FILE *, void *)) ;
bool stack_push(void *dp, struct stack *s) ;
void *stack_pop(struct stack *s) ;
void *stack_top(struct stack *s) ;
bool is_empty(struct stack *s) ;
void stack_destroy(struct stack *s) ;

