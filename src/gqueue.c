#include "queue.h"
#include "glist.h"
#include "gdsutils.h"

struct queue *queue_create(bool (* f)(void *, void *), int (* g)(FILE *, void *)) {
	struct queue *q = (struct queue*)(malloc(sizeof(struct queue)));
	q->glp = glist_create(f, g);

	return q;
}

bool queue_add_back(void *dp, struct queue *q) {
	bool success = add_back(dp, q->glp);

	return success;
}

void *queue_remove_front(struct queue *q) {
	void *result = remove_front(q->glp);

	return result;
}

bool is_queue_empty(const struct queue *q) {

	return is_empty(q->glp);
}

void queue_destroy(struct queue *q) {
	delete_glist(q->glp);

	free(q);
}
