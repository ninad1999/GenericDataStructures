#include "gtree.h"
#include "gdsutils.h"
#include <assert.h>

struct gtree *create_gtree(int (* f)(void *, void *), int (* g)(FILE *, void *)) {
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

static struct gtnode *create_gtnode(void *dp) {
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
	assert(gtp);
	return gtp->root == NULL;
}

struct gtnode *insert_gtnode(void *dp, struct gtnode *gtnp, struct gtree *gtp) {
	
	if (gtnp == NULL ) {
		gtnp = create_gtnode(dp);
	} else if (gtp->g_compare(dp, gtnp->datum) == -1) {
		gtnp->left = insert_gtnode(dp, gtnp->left, gtp);
	} else if (gtp->g_compare(dp, gtnp->datum) == 1) {
		gtnp->right = insert_gtnode(dp, gtnp->right, gtp);
	} else { // item already exists
		fprintf(stdout, "Datum already exists in the Generic Tree.\n");
	}

	return gtnp;
}
	
void gtree_insert(void *dp, struct gtree *gtp) {
	assert(gtp);

	if (dp == NULL) {
		fprintf(stderr, "Cannot insert a NULL datum in the generic tree.\n");
	} else {
		gtp->root = insert_gtnode(dp, gtp->root, gtp);
	}
}

struct gtnode *remove_gtnode(void *dp, struct gtnode *gtnp, struct gtree *gtp) {

	if (gtnp == NULL) {
		
		return NULL;
	}

	if (gtp->g_compare(dp, gtnp->datum) == -1) {
		gtnp->left = remove_gtnode(dp, gtnp->left, gtp);
	} else if (gtp->g_compare(dp, gtnp->datum) == 1) {
		gtnp->right = remove_gtnode(dp, gtnp->right, gtp);
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
		struct gtnode *next_node = gtnp->right;

		while(next_node->left) {
			next_node = next_node->left;
		}
		gtnp->datum = next_node->datum;
		gtnp->right = remove_gtnode(next_node->datum, gtnp->right, gtp);		
	}

	return gtnp;
}

void gtree_remove(void *dp, struct gtree *gtp) {
	assert(gtp);

	if (dp == NULL) {
		fprintf(stderr, "No node with a NULL datum exists in the tree.\n");
	} else {
		if (is_tree_empty(gtp)) {
			fprintf(stdout, "Tree is empty. No node can be removed\n");
		} else {
			gtp->root = remove_gtnode(dp, gtp->root, gtp);
		}
	}
}

bool gtree_lookup(void *dp, const struct gtree *gtp) {
	assert(gtp);
	
	bool success = false;

	if (dp == NULL) {
		fprintf(stderr, "No node with a NULL datum in the tree.\n");
	} else {

		struct gtnode *curr = gtp->root;

		while(curr) {
			if (gtp->g_compare(dp, curr->datum) == -1) {
				curr = curr->left;
			} else if (gtp->g_compare(dp, curr->datum) == 1) {
				curr = curr->right;
			} else {
				success = true;
				break;
			}
		}
	}

	if (success)
		fprintf(stdout, "Node found in the tree.\n");
	else 
		fprintf(stdout, "Node not found in the tree.\n");

	return success;
}


void free_gtnode(struct gtnode *gtnp) {
	if (gtnp) {
		free_gtnode(gtnp->left);
		free_gtnode(gtnp->right);
		free(gtnp);
	}
}

void gtree_destroy(struct gtree *gtp) {
	free_gtnode(gtp->root);
	free(gtp);
}

void print_gtnode(struct gtnode *gtnp, int space, struct gtree *gtp) {
	const int COUNT = 10;
	
	if (gtnp == NULL) {
		return;
	}

	space += COUNT;

	print_gtnode(gtnp->right, space, gtp);

	printf("\n");
	for (int i = COUNT; i < space; i++) {
		printf(" ");
	}
	gtp->g_print(stdout, gtnp->datum);

	print_gtnode(gtnp->left, space, gtp);
}

void print_gtree(struct gtree *gtp) {
	assert(gtp);
	
	print_gtnode(gtp->root, 0, gtp);
	printf("\n");
}

void print_inorder_gtnode(struct gtnode *gtnp, struct gtree *gtp) {
	if (gtnp == NULL) {
		return;
	}

	print_inorder_gtnode(gtnp->left, gtp);

	gtp->g_print(stdout, gtnp->datum);

	print_inorder_gtnode(gtnp->right, gtp);

}

void print_inorder(struct gtree *gtp) {
	assert(gtp);

	print_inorder_gtnode(gtp->root, gtp);
	printf("\n");
}

void print_preorder_gtnode(struct gtnode *gtnp, struct gtree *gtp) {
	if (gtnp == NULL) {
		return;
	}

	gtp->g_print(stdout, gtnp->datum);

	print_preorder_gtnode(gtnp->left, gtp);

	print_preorder_gtnode(gtnp->right, gtp);

}

void print_preorder(struct gtree *gtp) {
	assert(gtp);

	print_preorder_gtnode(gtp->root, gtp);
	printf("\n");
}

void print_postorder_gtnode(struct gtnode *gtnp, struct gtree *gtp) {
	if (gtnp == NULL) {
		return;
	}

	print_postorder_gtnode(gtnp->left, gtp);

	print_postorder_gtnode(gtnp->right, gtp);
	
	gtp->g_print(stdout, gtnp->datum);
}

void print_postorder(struct gtree *gtp) {
	assert(gtp);

	print_postorder_gtnode(gtp->root, gtp);
	printf("\n");
}

