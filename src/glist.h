#ifndef _GLIST_H_
#define _GLIST_H_

#include "gdsutils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*	Node of a generic linked list.*/
struct glnode {
    void *datum;          /* Pointer to an arbitrary datum. */
    struct glnode *next;
};

/*	The generic linked list. Apart from the pointer to its front node,
	it also has pointers to generic functions operating on the data. */
struct glist {
    struct glnode *front;

	/* A generic function to test equality of two data. */
	bool (*g_are_equal)(void *, void *);
	/* A generic function to print datum to a file. */	
	int (*g_print)(FILE*, void *);      
};

/*	Create a generic linked list.

	Parameters:
		Pointer to a generic function to test if two data are equal.
		Pointer to a generic function to print a datum to a file.

	Returns:
		A pointer to a generic list if it succeeds or NULL if it does not.
		The function fails if either of its arguments are NULL.
*/		
struct glist *glist_create(bool (*f)(void *, void *), int (*g)(FILE *, void *));

/*	Tells whether a generic list is empty.

	Parameters:
		A constant pointer to a generic list.

	Returns:
		true if the list has nodes, false if it does not.
		false if the function gets a NULL pointer.
*/
bool is_empty(const struct glist *glp);

/*	Adds a datum at the front of the list.

	Parameters:
		A pointer to the datum.
		A pointer to a generic linked list.

	Returns:
		true if the operation succeeds, false otherwise.
		The operation fails if either a new node could not be created or if the
		second argument to the function is NULL.
*/		
bool add_front(void *dp, struct glist *glp);

/*	Adds a datum at the back of the list.

	Parameters:
		A pointer to the datum.
		A pointer to a generic linked list.

	Returns:
		true if the operation succeeds, false otherwise.
		The operation fails if either a new node could not be created or if the
		second argument to the function is NULL.
*/		
bool add_back(void *dp, struct glist *glp);

/*	Inserts a datum at a given position of a list.

	Parameters:
		An integer telling the position where the datum is to be added. If it is -1
		then the datum is added at the back.
		A pointer to the datum.
		A pointer to a generic linked list.

	Returns:
		true if the operation succeeds, false otherwise.
		The operation fails if either a new node could not be created or if the
		second argument to the function is NULL or if the position where it is added is
		beyond the list's length. A negative number other than -1 also gives an error.
*/
bool insert_at(int n, void *dp, struct glist *glp);

/*	Removes a datum from the front of the list.

	Parameters:
		A pointer to a generic linked list.

	Returns:
		A pointer to the datum that was removed.
		NULL if the list is empty.
*/		
void *remove_front(struct glist *glp);

/*	Removes a datum from the rear end of the list.

	Parameters:
		A pointer to a generic linked list.

	Returns:
		A pointer to the datum that was removed.
		NULL if the list is empty.
*/		
void *remove_back(struct glist *glp);

/*	Removes a datum at the nth position in the list.

	Parameters:
		An integer >= -1 telling the position of the datum.
		A pointer to a generic linked list.

	Returns:
		The pointer to the datum if there is datum at the nth position, NULL otherwise.
*/		
void *remove_at(int n, struct glist *glp);

/*	Returns the length of the generic list. */
size_t glist_len(const struct glist *glp);

/*	Deletes the generic list. */
/*	User responsible to free memory allocated for elements of the glist. */
void delete_glist(struct glist *glp);

/*	Reverses the list in place. */
void glist_reverse(struct glist *glp);

/*	Reverses the list recursively. */
void glist_reverse_r(struct glist *glp);

/*	Prints a list to a file. */
void print_glist(FILE*fp, const struct glist *glp);

/*	Searches an item in a generic list.

	Parameters:
		A pointer to the datum to be searched.
		A pointer to the generic linked list.

	Returns:
		The position of the datum in the list if it is found, -1 otherwise.
*/
int glist_lookup(void *dp, const struct glist *glp);

/* Returns the item at position n in the glist
	
	Parameters:
		An integer n >= -1 for the position of the datum to be known
		The struct glist

	Returns:
		The value of the datum at position n
*/
void *item_at(int n, const struct glist *glp);
#endif
