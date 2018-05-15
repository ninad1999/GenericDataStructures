#include  "stack.h"
#include "gdsutils.h"
#include "glist.h"

struct stack *stack_create(bool (* f)(void *, void *), int (* g)(FILE *, void *)) {
	struct stack *s = (struct stack*)malloc(sizeof(struct stack));
	s->glp = glist_create(f, g);

	return s;
}

bool stack_push(void *dp, struct stack *s) {
	bool success = false;
	success = add_back(s->glp);

	return result;
}

void *stack_pop(struct stack *s) {
	void *result = NULL;
	result = remove_back(s->glp);

	return result;
}

void *stack_top(struct stack *s) {
	void *result = NULL;
	result = item_at(-1, s->glp);
	
	return result;
}

bool is_empty(struct stack *s) {

	return is_empty(s->glp);
}

void stack_destroy(struct stack *s) {
	delete_glist(s->glp);

	free(s);
}