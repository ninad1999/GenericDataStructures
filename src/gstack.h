#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack {
	struct glist *glp;
	bool (* g_are_equal)(void *, void *);
	int (* g_print)(FILE *, void *);
};

/* Creates the stack
	
	Parameters:
		A compare function
		A Print Function
	
	Returns:
		Returns the created stack
*/
struct stack *stack_create(bool (* f)(void *, void *), int (* g)(FILE *, void *)) ;

/* Pushes the element dp onto the stack
	
	Parameters:
		A void pointer dp, the element to be pushed on the stack
		Pointer to the generic stack
	
	Returns:
		A boolean value to indicate whether element has been pushed on the stack or not
*/
bool stack_push(void *dp, struct stack *s) ;

/* Removes the top most element from the stack

	Parameter:
		Pointer to the generic stack

	Returns:
		The value of the removed element
*/
void *stack_pop(struct stack *s) ;

// Returns a boolean value to indicate whether the stack is empty or not
bool is_stack_empty(const struct stack *s) ;

// Destroys the stack
// User resonsible to free memory allocated for elements added to stack.
void stack_destroy(struct stack *s) ;

