#include "gstack.h"
#include "gdsutils.h"
#include "glist.h"

struct stack *stack_create(bool (* f)(void *, void *), int (* g)(FILE *, void *)) 
{
	struct stack *s = (struct stack*)malloc(sizeof(struct stack));
	s->glp = glist_create(f, g);

	return s;
}

bool stack_push(void *dp, struct stack *s) 
{
	return add_back(dp, s->glp);
}

void *stack_pop(struct stack *s) 
{
	return remove_back(s->glp);
}

bool is_stack_empty(const struct stack *s) 
{
	return is_empty(s->glp);
}

void stack_destroy(struct stack *s) 
{
	delete_glist(s->glp);

	free(s);
}

