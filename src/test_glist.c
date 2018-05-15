#include "glist.h"
#include "gdsutils.h"

#include <stdio.h>

void quick_tests()
{
	struct glist *pintl = glist_create(are_equal_int, fprint_int);
	int elements[] = {1, 2, 3, 4, 5, 6};

	add_front(elements + 0, pintl);
	add_front(elements + 1, pintl);
	add_front(elements + 2, pintl);
	add_front(elements + 3, pintl);
	add_front(elements + 4, pintl);
	add_front(elements + 5, pintl);

	print_glist(stdout, pintl);

	int elements2[] = {8, 9 ,10, 11, 12, 13};

	add_back(elements2 + 0, pintl);
	add_back(elements2 + 1, pintl);
	add_back(elements2 + 2, pintl);
	add_back(elements2 + 3, pintl);
	add_back(elements2 + 4, pintl);
	add_back(elements2 + 5, pintl);

	int elements3[] = {14, 15, 16, 17, 18, 19};

	insert_at(0, elements3 + 0, pintl);
	insert_at(1, elements3 + 1, pintl);
	insert_at(2, elements3 + 2, pintl);
	insert_at(3, elements3 + 3, pintl);
	insert_at(4, elements3 + 4, pintl);
	insert_at(-1, elements3 + 5, pintl);

	add_front(NULL, pintl);
	add_back(NULL, pintl);
	insert_at(3, NULL, pintl);
	print_glist(stdout, pintl);

	int pos = glist_lookup(elements + 3, pintl);
	if (pos == -1) 
		printf("Element %d was not found in the list.\n", elements[3]);
	else
		printf("Element %d found at position %d.\n", elements[3], pos);

	int n = 7;
	pos = glist_lookup(&n, pintl);
	if (pos == -1) 
		printf("Element %d was not found in the list.\n", n);
	else
		printf("Element %d found at position %d.\n", n, pos);

	glist_reverse(pintl);
	print_glist(stdout, pintl);

	glist_reverse_r(pintl);
	print_glist(stdout, pintl);
	
	int len = glist_len(pintl);
	printf("%d\n", len);

	for (int i = len; i >= 0; i--) {
		remove_back(pintl);
	}

	print_glist(stdout, pintl);
	
	remove_back(pintl);
	print_glist(stdout, pintl);
	
	delete_glist(pintl);
}

int main(int argc, char *argv[], char *envp[])
{
	quick_tests();

	return 0;
}
