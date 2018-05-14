#include "glist.h"
#include "gdsutils.h"

#include <stdio.h>

void quick_tests()
{
	struct glist *pintl = glist_create(are_equal_int, fprint_int);
	int elements[] = {1, 2, 3, 4, 5, 6};

	add_back(elements + 0, pintl);
	add_back(elements + 1, pintl);
	add_back(elements + 2, pintl);
	add_back(elements + 3, pintl);
	add_back(elements + 4, pintl);
	add_back(elements + 5, pintl);

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

	delete_glist(pintl);
}

int main(int argc, char *argv[], char *envp[])
{
	quick_tests();

	return 0;
}