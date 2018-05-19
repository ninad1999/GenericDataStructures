#include "gtree.h"
#include "gdsutils.h"

int quick_test(void) {
	
	struct gtree *gtp = create_gtree(compare_int, fprint_int);
	int elements[] = {6, 2, 3, 1, 9, 5, 7};

	gtree_insert(elements, gtp);
	gtree_insert(elements + 1, gtp);
	gtree_insert(elements + 2, gtp);
	gtree_insert(elements + 3, gtp);
	gtree_insert(elements + 4, gtp);
	gtree_insert(elements + 5, gtp);
	gtree_insert(elements + 6, gtp);
	gtree_insert(NULL, gtp);
	
	print_gtree(gtp);

	printf("Inorder: ");
	print_inorder(gtp);
	printf("Postorder: ");
	print_postorder(gtp);
	printf("Preorder: ");
	print_preorder(gtp);

	int look = gtree_lookup(elements + 4, gtp);
	int i = 10;
	int look2 = gtree_lookup(&i, gtp);
	gtree_lookup(NULL, gtp);
	printf("%d  %d\n", look, look2);

	gtree_remove(elements + 3, gtp);
	gtree_remove(NULL, gtp);
	gtree_remove(elements + 4, gtp);
	gtree_remove(elements + 2, gtp);
	gtree_remove(elements + 1, gtp);
	gtree_remove(elements , gtp);
	gtree_remove(elements + 5, gtp);
	gtree_remove(elements + 6, gtp);
	gtree_remove(NULL, gtp);

	print_gtree(gtp);

	gtree_destroy(gtp);
	
	return 0;
}

int main(void) {

	quick_test();

	return 0;

}



