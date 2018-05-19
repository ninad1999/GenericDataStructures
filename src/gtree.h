#ifndef _GTREE_H_
#define _GTREE_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct gtnode {
	void *datum;
	struct gtnode *left;
	struct gtnode *right;
};

struct gtree {
	struct gtnode *root;

	/* A generic function to compare two data. */
	int (*g_compare)(void *, void *);

	/* A generic function to print datum to a file. */
	int (*g_print)(FILE*, void *);
};

/* Creates a Generic Binary Search Tree
		
		Parameters:
			A Generic Compare function
			A Generic Print function

		Returns:
			The created Generic Tree
*/
struct gtree *create_gtree(int (* f)(void *, void *), int (* g)(FILE *, void *)) ;

/*	Tells whether the generic tree is empty.

		Parameters:
			A constant pointer to a generic tree.

		Returns:
			true if the tree has nodes, false if it does not.
			false if the function gets a NULL pointer.
*/
bool is_tree_empty(const struct gtree *gtp) ;

/*	Inserts a datum in the tree.

	Parameters:
		A pointer to the datum.
		A pointer to a generic tree.
*/
void gtree_insert(void *dp, struct gtree *gtp) ;

/*	Removes the datum from the tree.

		A pointer to the datum.
		A pointer to a generic tree.
*/
void gtree_remove(void *dp, struct gtree *gtp) ;

/*	Searches the datum in the generic tree.

	Parameters:
		A pointer to the datum to be searched.
		A pointer to the generic tree.

	Returns:
		True if node exists in tree otherwise false.
*/
bool gtree_lookup(void *dp, const struct gtree *gtp) ;

// Deletes the generic Tree.
// User responsible to free memory allocated for datum
void gtree_destroy(struct gtree *gtp) ;

// Prints Generic Tree in inorder traversal.
void print_inorder(struct gtree *gtp) ;

// Prints Generic Tree in preorder traversal.
void print_preorder(struct gtree *gtp) ;

// Prints Generic Tree in postorder traversal.
void print_postorder(struct gtree *gtp) ;

// Prints a 2D Generic Tree.
void print_gtree(struct gtree *gtp) ;
#endif
