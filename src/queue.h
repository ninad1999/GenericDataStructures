#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue {
	struct glist *glp;
	bool (* g_are_equal)(void *, void *);
	int (* g_print)(FILE *, void *);
}

/* Creates the queue
	
	Parameters:
		A compare function
		A Print Function
	
	Returns:
		Returns the created queue
*/
struct queue *queue_create(bool (* f)(void *, void *), int (* g)(FILE *, void *)) ;

/* Adds the element dp to the queue
	
	Parameters:
		A void pointer dp to be added to queue
		Pointer to the Queue
	
	Returns:
		A boolean value to indicate whether element has been added to the queue or not
*/
bool add_back(void *dp, struct queue *q) ;

/* Removes the bottom most element from the queue

	Parameter:
		The Queue

	Returns:
		The value of the removed element
*/
void *remove_front(struct queue *q) ;

// Returns a boolean value to indicate whether the queue is empty or not
bool is_empty(const struct queue *q) ;

// Destroys the queue
void stack_destroy(struct queue *q) ;
