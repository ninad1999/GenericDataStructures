#include "gtree.h"
#include "gdsutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct gtree *create_gtree(bool (* f)(void *, void *), int (* g)(FILE *, void *)) {
	struct gtree *gtp = NULL;

	if (f && g) {
		gtp = (struct gtree *)malloc(sizeof(struct gtree));

		if (gtp) {
			gtp->root = NULL;
			gtp->g_compare = f;
			gtp->g_print = g;
		} else {
			fprintf(stderr, "Unable to allocate memory to create a tree.\n");
		}
	}

    return gtp;
}

static gtnode *create_gtnode(void *dp) {
	struct gtnode *gtnp = NULL;

	if (dp) {
		gtnp = (struct gtnode *)malloc(sizeof(struct gtnode));
		
		if (gtnp) {
			gtnp->datum = dp;
			gtnp->left = NULL;
			gtnp->right = NULL;
		}
	} else {
		fprintf(stderr, "Creating a node of the generic tree with NULL datum.\n");
	}
	
	return gtnp; 
}

bool is_tree_empty(const struct gtree *gtp) {

	return gtp->root == NULL;
}

struct gtnode *insert_gtnode(void *dp, struct gtnode *gtnp, struct gtree *gtp) {
	
	if (gtnp == NULL ) {
		gtnp = create_gtnode(dp);
	} else if (gtp->g_compare(dp, gtnp->datum) == -1) {
		gtnp->left = insert_gtnode(dp, gtnp->left);
	} else if (gtp->g_compare(dp, gtnp->datum) == 1) {
		gtnp->right = insert_gtnode(dp, gtnp->right);
	} else { // item already exists
		fprintf(stdout, "Datum already exists in the Generic Tree.\n");
	}

	return gtnp;
}
	
void insert(void *dp, struct gtree *gtp) {
	gtp->root = insert_gtnode(dp, gtp->root, gtp);
}

struct gtnode *remove_gtnode(void *dp, struct gtnode *gtnp, struct gtree *gtp) {
	if (gtnp == NULL) {
		
		return NULL;
	}

	if (gtp->g_compare(dp, gtnp->datum) == -1) {
		gtnp->left = remove_gtnode(dp, gtnp->left);
	} else if (gtp->compare(dp, gtnp->datum) == 1) {
		gtnp->right = remove_gtnode(dp, gtnp->right)
	} else if (gtnp->left == NULL) {
		struct gtnode *new = gtnp->right;
		free(gtnp);

		return new;
	} else if (gtnp->right == NULL) {
		struct gtnode *new = gtnp->left;
		free(gtnp);

		return new;
	} else {		
		// finding next largest datum
		struct gtnext_node *next_node = gtnp->right;

		while(next_node->left) {
			next_node = next_node->left;
		}
		gtnp->datum = next_node->datum;
		gtnp->right = remove_gtnext_node(next_node->datum, gtnp->right);		
	}

	return gtnp;
}

void remove(void *dp, struct gtree *gtp) {
	gtp->root = remove_gtnode(dp, gtp->root, gtp);
}

bool *lookup(void *dp, const struct gtree *gtp) {
	bool success = false;

	struct gtnode *curr = gtp->root;

	while(curr) {
		if (gtp->g_compare(dp, curr->datum) == -1) {
			curr = curr->left;
		} else if (gtp->g_compare(dp, curr->datum) == 1) {
			curr = curr->right;
		} else {
			success = true;
		}
	}

	return success;
}


void free_gtnode(struct gtnode *gtnp) {
	if (gtnp) {
		free_gtnode(gtnp->left);
		free_gtnode(gtnp->right);
		free(gtnp);
	}
}

void destroy(struct gtree *gtp) {
	free_gtnode(gtp->root);
	free(gtp);
}

void print_gtnode(struct gtnode *gtnp, int space, struct gtree *gtp) {
	const int COUNT = 10;
	
	if (gtnp == NULL) {
		return;
	}

	space += COUNT;

	print_gtnode(gtnp->right, space);

	printf("\n");
	for (int i = COUNT; i < space; i++) {
		printf(" ");
	}
	gtp->g_print(stdout, gtnp->datum);

	print_gnode(gtnp->left, space);
}

void print_gtree(struct gtree *gtp) {
	print_gtnode(gtp->root, 0, gtp);

}

void print_inorder_gtnode(struct gtnode *gtnp, struct gtree *gtp) {
	if (gtnp == NULL) {
		return;
	}

	print_inorder_gtnode(gtnp->left);

	gtp->g_print(stdout, gtnp->datum);

	print_inorder_gtnode(gtnp->right);

}

void print_inorder(struct gtree *gtp) {
	print_inorder_gtnode(gtp->root, gtp);
}

void print_preorder_gtnode(struct gtnode *gtnp, struct gtree *gtp) {
	if (gtnp == NULL) {
		return;
	}

	gtp->g_print(stdout, gtnp->datum);

	print_preorder_gtnode(gtnp->left);

	print_preorder_gtnode(gtnp->right);

}

void print_preorder(struct gtree *gtp) {
	print_preorder_gtnode(gtp->root, gtp);
}

void print_postorder_gtnode(struct gtnode *gtnp, struct gtree *gtp) {
	if (gtnp == NULL) {
		return;
	}

	print_postorder_gtnode(gtnp->left);

	print_postorder_gtnode(gtnp->right);
	
	gtp->g_print(stdout, gtnp->datum);
}

void print_postorder(struct gtree *gtp) {
	print_postorder_gtnode(gtp->root, gtp);
}

