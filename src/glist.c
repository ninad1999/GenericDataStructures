#include "glist.h"



static struct glnode *create_glnode(void *dp)
{
    struct glnode* glnp = NULL;

	if (dp) {
		glnp = (struct glnode*)malloc(sizeof(struct glnode));

		if (glnp) {
			glnp->datum = dp;
			glnp->next = NULL;
		}
	} else {
		fprintf(stderr, "Creating a node of a generic linked list with NULL datum.\n");
	}

    return glnp;
}

struct glist *glist_create(bool (*f)(void *, void *), int (*g)(FILE *, void *))
{
    struct glist *glp = NULL;

	if (f && g) {
		glp = (struct glist *)malloc(sizeof(struct glist));

		if (glp) {
			glp->front = NULL;
			glp->g_are_equal = f;
			glp->g_print = g;
		} else {
			fprintf(stderr, "Unable to allocate memory to create a list.\n");
		}
	}

    return glp;
}

bool is_empty(const struct glist *glp)
{
	return (!glp || !(glp->front));
}

bool insert_at(int n, void *dp, struct glist *glp)
{
	bool success = true;

	if (n < -1) success = false;
	if (!dp || !glp) {
		success = false;
		fprintf(stderr, "One or both arguments to %s are NULL.\n", __FUNCTION__);
	}

	struct glnode *new_node = create_glnode(dp);
	if (!new_node) {
		success = false;
		fprintf(stderr, 
				"Unable to allocate memory to create a new node in %s.\n",
				__FUNCTION__);
	}

	if (success && n == -1) {
		struct glnode *curr = glp->front;

		if (!curr) { // The list is empty.
			glp->front = new_node;
		} else {
			while (curr->next)
				curr = curr->next;

			curr->next = new_node;
		}
	} else if (success && n == 0) {
		struct glnode *curr = glp->front;
		glp->front = new_node;
		new_node->next = curr;
	} else {
		struct glnode *curr = glp->front;
		struct glnode *prev = NULL;
		int pos = 0;

		while (curr && pos != n) {
			prev = curr;
			curr = curr->next;
			++pos;
		}

		if (curr && pos == n) {
			prev->next = new_node;
			new_node->next = curr;
		} else {
			// n is beyond the list.
			success = false;
			fprintf(stderr,
					"Adding element at a position beyond list's length.\n");
		}
	}

    return success;       
}

bool add_front(void *dp, struct glist *glp)
{
    return insert_at(0, dp, glp); 
}

bool add_back(void *dp, struct glist *glp)
{
    return insert_at(-1, dp, glp);
}

void *remove_at(int n, struct glist *glp)
{
	bool success = (n >= -1 && !is_empty(glp));
	void *dp = NULL;

	if (success) {
		if (n == 0) {
			assert(glp->front);

			struct glnode *tmp = NULL;

			tmp = glp->front;
			dp = tmp->datum;
			glp->front = tmp->next;

			free(tmp);
		} else if (n == -1) {
			struct glnode *prev = NULL;
			struct glnode *curr = glp->front;

			while (curr->next) {
				prev = curr;
				curr = curr->next;
			}

			dp = curr->datum;
			prev->next = NULL;

			free(curr);
		} else {
			struct glnode *prev = NULL;
			struct glnode *curr = glp->front;
			int pos = 0;

			while (curr->next && pos != n) {
				prev = curr;
				curr = curr->next;
				++pos;
			}

			if (pos == n) { // We have gone past the end of the list.
				prev->next = curr->next;
				dp = curr->datum;
				free(curr);
			} else {
				fprintf(stderr, "Trying to remove an element past the list's end.\n");
				success = false;
			}
		}
	}

    return dp;
}

void *remove_front(struct glist *glp)
{
    return remove_at(0, glp);
}

void *remove_back(struct glist *glp)
{
    return remove_at(-1, glp);
}

size_t glist_len(const struct glist *glp)
{
	size_t L = 0;

	if (!is_empty(glp)) {
		struct glnode *curr = glp->front;

		while (curr) {
			++L;
			curr = curr->next;
		}
	}

    return L;
}

void delete_glist(struct glist *glp)
{
	/* We do not free the pointer dp because this module has not created it. */
    while (!is_empty(glp))
        remove_front(glp);

    free(glp);
}

void glist_reverse(struct glist *glp)
{
    struct glnode *prevnode = NULL;
    struct glnode *currnode = glp->front;
    struct glnode *nextnode = NULL;

    while (currnode) {
        nextnode = currnode->next;
        currnode->next = prevnode;
        prevnode = currnode;
        currnode = nextnode;
    }

    glp->front = prevnode;
}

static struct glnode *reverse_list_r(struct glnode *node)
{
    struct glnode *first = node;
    struct glnode *rest;

    if (first == NULL || first->next == NULL) return first;

    rest = reverse_list_r(first->next);
	/*
	Suppose that the list is a -> b -> c -> d. Then the first step
	in the recursive algorithm will result in a -> b <- c <- d. Note 
	the change in arrow directions. We now have to make b point to a.
	This is what the first statement below this comment does. Next, we
	must set the "next" pointer of 'a' to NULL. This is done in the 
	second statement below this comment.
	*/
    first->next->next = first;
    first->next = NULL;

    return rest;
}

void glist_reverse_r(struct glist *glp)
{
    glp->front = reverse_list_r(glp->front);
}

void print_glist(FILE*fp, const struct glist *glp)
{
	if (!is_empty(glp) && fp) {
		struct glnode *curr = glp->front;

		while (curr) {
			glp->g_print(fp, curr->datum);
			fprintf(fp, " -> ");
			curr = curr->next;
		}

		fprintf(fp, "NULL.\n");
	}
}

int glist_lookup(void *dp, const struct glist *glp)
{
	int pos = -1;

	if (!is_empty(glp)) {
		struct glnode *curr = glp->front;

		pos = 0;
		while (curr && !glp->g_are_equal(dp, curr->datum)) {
			curr = curr->next;
			++pos;
		}

		if (!curr) pos = -1;
	}

	return pos;
}

