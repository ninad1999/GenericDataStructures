#include "gdsutils.h"
#include <unistd.h>

void test_are_equal_int_1()
{
	int x = 1;
	int y = 1;

	bool result = are_equal_int(&x, &y);

	if (result == true)
		printf("%s passed.\n", __func__);
	else
		printf("%s failed.\n", __func__);
}

void test_are_equal_int_2()
{
	int x = 1;
	int y = 2;

	bool result = are_equal_int(&x, &y);

	if (result == false)
		printf("%s sub-test 1 passed.\n", __func__);
	else
		printf("%s sub-test 1 failed.\n", __func__);

	result = are_equal_int(&y, &x);

	if (result == false)
		printf("%s sub-test 2 passed.\n", __func__);
	else
		printf("%s sub-test 2 failed.\n", __func__);
}

void test_are_equal_int_3()
{
	int x = 1;

	bool result = are_equal_int(&x, NULL);

	if (result == false)
		printf("%s sub-test 1 passed.\n", __func__);
	else
		printf("%s sub-test 1 failed.\n", __func__);

	result = are_equal_int(NULL, &x);

	if (result == false)
		printf("%s sub-test 2 passed.\n", __func__);
	else
		printf("%s sub-test 2 failed.\n", __func__);

	result = are_equal_int(NULL, NULL);

	if (result == false)
		printf("%s sub-test 3 passed.\n", __func__);
	else
		printf("%s sub-test 3 failed.\n", __func__);
}

void test_are_equal_int_4()
{
	int x = 1;
	float y = 1;
	double z = 1;
	short w = 1;
	long u = 1;

	bool result = are_equal_int(&x, &y);

	if (result == false)
		printf("%s sub-test 1 passed.\n", __func__);
	else
		printf("%s sub-test 1 failed.\n", __func__);

	result = are_equal_int(&y, &x);

	if (result == false)
		printf("%s sub-test 2 passed.\n", __func__);
	else
		printf("%s sub-test 2 failed.\n", __func__);

	result = are_equal_int(&x, &z);

	if (result == false)
		printf("%s sub-test 3 passed.\n", __func__);
	else
		printf("%s sub-test 3 failed.\n", __func__);

	result = are_equal_int(&z, &x);

	if (result == false)
		printf("%s sub-test 4 passed.\n", __func__);
	else
		printf("%s sub-test 4 failed.\n", __func__);

	result = are_equal_int(&x, &w);

#ifdef __MACH__	
	bool expected_result = true;
#endif
#ifdef __linux__
	bool expected_result = false;
#endif

	if (result == expected_result)
		printf("%s sub-test 5 passed.\n", __func__);
	else
		printf("%s sub-test 5 failed.\n", __func__);

	result = are_equal_int(&w, &x);

	if (result == expected_result)
		printf("%s sub-test 6 passed.\n", __func__);
	else
		printf("%s sub-test 6 failed.\n", __func__);

	result = are_equal_int(&x, &u);

	if (result == true)
		printf("%s sub-test 7 passed.\n", __func__);
	else
		printf("%s sub-test 7 failed.\n", __func__);

	result = are_equal_int(&u, &x);

	if (result == true)
		printf("%s sub-test 8 passed.\n", __func__);
	else
		printf("%s sub-test 8 failed.\n", __func__);
}

void test_are_equal_double_1()
{
	double x = 1.00;
	double y = 1.00;

	bool result = are_equal_double(&x, &y);

	if (result == true)
		printf("%s passed.\n", __func__);
	else
		printf("%s failed.\n", __func__);
}

void test_are_equal_double_2()
{
	double x = 1;
	double y = 2;

	bool result = are_equal_double(&x, &y);

	if (result == false)
		printf("%s sub-test 1 passed.\n", __func__);
	else
		printf("%s sub-test 1 failed.\n", __func__);

	result = are_equal_double(&y, &x);

	if (result == false)
		printf("%s sub-test 2 passed.\n", __func__);
	else
		printf("%s sub-test 2 failed.\n", __func__);
}

void test_are_equal_double_3()
{
	double x = 1;

	bool result = are_equal_double(&x, NULL);

	if (result == false)
		printf("%s sub-test 1 passed.\n", __func__);
	else
		printf("%s sub-test 1 failed.\n", __func__);

	result = are_equal_double(NULL, &x);

	if (result == false)
		printf("%s sub-test 2 passed.\n", __func__);
	else
		printf("%s sub-test 2 failed.\n", __func__);

	result = are_equal_double(NULL, NULL);

	if (result == false)
		printf("%s sub-test 3 passed.\n", __func__);
	else
		printf("%s sub-test 3 failed.\n", __func__);
}

void test_are_equal_double_4()
{
	int x = 1;
	float y = 1;
	double z = 1;
	short w = 1;
	long u = 1;

	bool result = are_equal_double(&z, &y);

	if (result == false)
		printf("%s sub-test 1 passed.\n", __func__);
	else
		printf("%s sub-test 1 failed.\n", __func__);

	result = are_equal_double(&y, &z);

	if (result == false)
		printf("%s sub-test 2 passed.\n", __func__);
	else
		printf("%s sub-test 2 failed.\n", __func__);

	result = are_equal_double(&z, &x);

	if (result == false)
		printf("%s sub-test 3 passed.\n", __func__);
	else
		printf("%s sub-test 3 failed.\n", __func__);

	result = are_equal_double(&x, &z);

	if (result == false)
		printf("%s sub-test 4 passed.\n", __func__);
	else
		printf("%s sub-test 4 failed.\n", __func__);

	result = are_equal_double(&z, &w);

	if (result == false)
		printf("%s sub-test 5 passed.\n", __func__);
	else
		printf("%s sub-test 5 failed.\n", __func__);

	result = are_equal_double(&w, &z);

	if (result == false)
		printf("%s sub-test 6 passed.\n", __func__);
	else
		printf("%s sub-test 6 failed.\n", __func__);

	result = are_equal_double(&z, &u);

	if (result == false)
		printf("%s sub-test 7 passed.\n", __func__);
	else
		printf("%s sub-test 7 failed.\n", __func__);

	result = are_equal_double(&u, &z);

	if (result == false)
		printf("%s sub-test 8 passed.\n", __func__);
	else
		printf("%s sub-test 8 failed.\n", __func__);
}

void test_are_equal_float_1()
{
	float x = 1.00;
	float y = 1.00;

	bool result = are_equal_float(&x, &y);

	if (result == true)
		printf("%s passed.\n", __func__);
	else
		printf("%s failed.\n", __func__);
}

void test_are_equal_float_2()
{
	float x = 1;
	float y = 2;

	bool result = are_equal_float(&x, &y);

	if (result == false)
		printf("%s sub-test 1 passed.\n", __func__);
	else
		printf("%s sub-test 1 failed.\n", __func__);

	result = are_equal_float(&y, &x);

	if (result == false)
		printf("%s sub-test 2 passed.\n", __func__);
	else
		printf("%s sub-test 2 failed.\n", __func__);
}

void test_are_equal_float_3()
{
	float x = 1;

	bool result = are_equal_float(&x, NULL);

	if (result == false)
		printf("%s sub-test 1 passed.\n", __func__);
	else
		printf("%s sub-test 1 failed.\n", __func__);

	result = are_equal_float(NULL, &x);

	if (result == false)
		printf("%s sub-test 2 passed.\n", __func__);
	else
		printf("%s sub-test 2 failed.\n", __func__);

	result = are_equal_float(NULL, NULL);

	if (result == false)
		printf("%s sub-test 3 passed.\n", __func__);
	else
		printf("%s sub-test 3 failed.\n", __func__);
}

void test_are_equal_float_4()
{
	int x = 1;
	float y = 1;
	double z = 1;
	short w = 1;
	long u = 1;

	bool result = are_equal_float(&x, &y);

	if (result == false)
		printf("%s sub-test 1 passed.\n", __func__);
	else
		printf("%s sub-test 1 failed.\n", __func__);

	result = are_equal_float(&y, &x);

	if (result == false)
		printf("%s sub-test 2 passed.\n", __func__);
	else
		printf("%s sub-test 2 failed.\n", __func__);

	result = are_equal_float(&y, &z);

	if (result == false)
		printf("%s sub-test 3 passed.\n", __func__);
	else
		printf("%s sub-test 3 failed.\n", __func__);

	result = are_equal_float(&z, &y);

	if (result == false)
		printf("%s sub-test 4 passed.\n", __func__);
	else
		printf("%s sub-test 4 failed.\n", __func__);

	result = are_equal_float(&y, &w);

	if (result == false)
		printf("%s sub-test 5 passed.\n", __func__);
	else
		printf("%s sub-test 5 failed.\n", __func__);

	result = are_equal_float(&w, &y);

	if (result == false)
		printf("%s sub-test 6 passed.\n", __func__);
	else
		printf("%s sub-test 6 failed.\n", __func__);

	result = are_equal_float(&y, &u);

	if (result == false)
		printf("%s sub-test 7 passed.\n", __func__);
	else
		printf("%s sub-test 7 failed.\n", __func__);

	result = are_equal_float(&u, &y);

	if (result == false)
		printf("%s sub-test 8 passed.\n", __func__);
	else
		printf("%s sub-test 8 failed.\n", __func__);
}

void test_are_equal_char_1()
{
	char x = 'a';
	char y = 'a';

	bool result = are_equal_char(&x, &y);

	if (result == true)
		printf("%s passed.\n", __func__);
	else
		printf("%s failed.\n", __func__);
}

void test_are_equal_char_2()
{
	char x = 'a';
	char y = 'b';

	bool result = are_equal_char(&x, &y);

	if (result == false)
		printf("%s sub-test 1 passed.\n", __func__);
	else
		printf("%s sub-test 1 failed.\n", __func__);

	result = are_equal_char(&y, &x);

	if (result == false)
		printf("%s sub-test 2 passed.\n", __func__);
	else
		printf("%s sub-test 2 failed.\n", __func__);
}

void test_are_equal_char_3()
{
	char x = 'a';

	bool result = are_equal_char(&x, NULL);

	if (result == false)
		printf("%s sub-test 1 passed.\n", __func__);
	else
		printf("%s sub-test 1 failed.\n", __func__);

	result = are_equal_char(NULL, &x);

	if (result == false)
		printf("%s sub-test 2 passed.\n", __func__);
	else
		printf("%s sub-test 2 failed.\n", __func__);

	result = are_equal_char(NULL, NULL);

	if (result == false)
		printf("%s sub-test 3 passed.\n", __func__);
	else
		printf("%s sub-test 3 failed.\n", __func__);
}

void test_are_equal_char_4()
{
	char v = 'a';
	int x = 1;
	float y = 1;
	double z = 1;
	short w = 1;
	long u = 1;

	bool result = are_equal_char(&v, &y);

	if (result == false)
		printf("%s sub-test 1 passed.\n", __func__);
	else
		printf("%s sub-test 1 failed.\n", __func__);

	result = are_equal_char(&y, &v);

	if (result == false)
		printf("%s sub-test 2 passed.\n", __func__);
	else
		printf("%s sub-test 2 failed.\n", __func__);

	result = are_equal_char(&v, &z);

	if (result == false)
		printf("%s sub-test 3 passed.\n", __func__);
	else
		printf("%s sub-test 3 failed.\n", __func__);

	result = are_equal_char(&z, &v);

	if (result == false)
		printf("%s sub-test 4 passed.\n", __func__);
	else
		printf("%s sub-test 4 failed.\n", __func__);

	result = are_equal_char(&v, &w);

	if (result == false)
		printf("%s sub-test 5 passed.\n", __func__);
	else
		printf("%s sub-test 5 failed.\n", __func__);

	result = are_equal_char(&w, &v);

	if (result == false)
		printf("%s sub-test 6 passed.\n", __func__);
	else
		printf("%s sub-test 6 failed.\n", __func__);

	result = are_equal_char(&v, &u);

	if (result == false)
		printf("%s sub-test 7 passed.\n", __func__);
	else
		printf("%s sub-test 7 failed.\n", __func__);

	result = are_equal_char(&u, &v);

	if (result == false)
		printf("%s sub-test 8 passed.\n", __func__);
	else
		printf("%s sub-test 8 failed.\n", __func__);

	result = are_equal_char(&x, &v);

	if (result == false)
		printf("%s sub-test 7 passed.\n", __func__);
	else
		printf("%s sub-test 7 failed.\n", __func__);

	result = are_equal_char(&v, &x);

	if (result == false)
		printf("%s sub-test 8 passed.\n", __func__);
	else
		printf("%s sub-test 8 failed.\n", __func__);
}

void test_fprint_int() 
{
	int a = 2;
	int b;

	FILE *fp = fopen("test.txt", "w");
	fprint_int(fp, &a);
	fclose(fp);

	fp = fopen("test.txt", "r");
	fscanf(fp, "%d", &b);
	fclose(fp);

	if (a == b)
		printf("%s passed.\n", __func__);
	else
		printf("%s failed.\n", __func__);

	unlink("test.txt");
}

void test_fprint_double() 
{
	double c = 2;
	double d;

	FILE *fp = fopen("test.txt", "w");
	fprint_double(fp, &c);
	fclose(fp);

	fp = fopen("test.txt", "r");
	fscanf(fp, "%lf", &d);
	fclose(fp);

	if (are_equal_double(&c, &d))
		printf("%s passed.\n", __func__);
	else
		printf("%s failed.\n", __func__);

	unlink("test.txt");
}

void test_fprint_char() 
{
	char e = 'a';
	char f;

	FILE *fp = fopen("test.txt", "w");
	fprint_char(fp, &e);
	fclose(fp);

	fp = fopen("test.txt", "r");
	fscanf(fp, "%c", &f);
	fclose(fp);

	if (e == f)
		printf("%s passed.\n", __func__);
	else
		printf("%s failed.\n", __func__);

	unlink("test.txt");
}

void test_fprint_float() 
{
	float g = 2;
	float h;

	FILE *fp = fopen("test.txt", "w");
	fprint_float(fp, &g);
	fclose(fp);

	fp = fopen("test.txt", "r");
	fscanf(fp, "%f", &h);
	fclose(fp);

	if (are_equal_float(&g, &h))
		printf("%s passed.\n", __func__);
	else
		printf("%s failed.\n", __func__);

	unlink("test.txt");
}


void test_compare_int_1()
{
	int x = 1;
	int y = 2;
	int z = 1;

	int result = compare_int(&x, &y);

	if (result == -1)
		printf("%s subtest 1 passed.\n", __func__);
	else
		printf("%s subtest 1 failed.\n", __func__);

	result = compare_int(&y, &x);
		
	if (result == 1)
		printf("%s subtest 2 passed.\n", __func__);
	else
		printf("%s subtest 2 failed.\n", __func__);
	
	result = compare_int(&x, &z);
		
	if (result == 0)
		printf("%s subtest 3 passed.\n", __func__);
	else
		printf("%s subtest 3 failed.\n", __func__);
	
	result = compare_int(&z, &x);
		
	if (result == 0)
		printf("%s subtest 4 passed.\n", __func__);
	else
		printf("%s subtest 4 failed.\n", __func__);
	
}

void test_compare_double_1()
{
	double x = 1;
	double y = 2;
	double z = 1;

	int result = compare_double(&x, &y);

	if (result == -1)
		printf("%s subtest 1 passed.\n", __func__);
	else
		printf("%s subtest 1 failed.\n", __func__);

	result = compare_double(&y, &x);
		
	if (result == 1)
		printf("%s subtest 2 passed.\n", __func__);
	else
		printf("%s subtest 2 failed.\n", __func__);
	
	result = compare_double(&x, &z);
		
	if (result == 0)
		printf("%s subtest 3 passed.\n", __func__);
	else
		printf("%s subtest 3 failed.\n", __func__);
	
	result = compare_double(&z, &x);
		
	if (result == 0)
		printf("%s subtest 4 passed.\n", __func__);
	else
		printf("%s subtest 4 failed.\n", __func__);
	
}

void test_compare_float_1()
{
	float x = 1;
	float y = 2;
	float z = 1;

	int result = compare_float(&x, &y);

	if (result == -1)
		printf("%s subtest 1 passed.\n", __func__);
	else
		printf("%s subtest 1 failed.\n", __func__);

	result = compare_float(&y, &x);
		
	if (result == 1)
		printf("%s subtest 2 passed.\n", __func__);
	else
		printf("%s subtest 2 failed.\n", __func__);
	
	result = compare_float(&x, &z);
		
	if (result == 0)
		printf("%s subtest 3 passed.\n", __func__);
	else
		printf("%s subtest 3 failed.\n", __func__);
	
	result = compare_float(&z, &x);
		
	if (result == 0)
		printf("%s subtest 4 passed.\n", __func__);
	else
		printf("%s subtest 4 failed.\n", __func__);
	
}

void test_compare_char_1()
{
	char x = 'a';
	char y = 'b';
	char z = 'a';

	int result = compare_char(&x, &y);

	if (result == -1)
		printf("%s subtest 1 passed.\n", __func__);
	else
		printf("%s subtest 1 failed.\n", __func__);

	result = compare_char(&y, &x);
		
	if (result == 1)
		printf("%s subtest 2 passed.\n", __func__);
	else
		printf("%s subtest 2 failed.\n", __func__);
	
	result = compare_char(&x, &z);
		
	if (result == 0)
		printf("%s subtest 3 passed.\n", __func__);
	else
		printf("%s subtest 3 failed.\n", __func__);
	
	result = compare_char(&z, &x);
		
	if (result == 0)
		printf("%s subtest 4 passed.\n", __func__);
	else
		printf("%s subtest 4 failed.\n", __func__);
	
}

/*int test_compare_int_2()
{
	int x = 1;

	int result = compare_int(&x, NULL);

	return result;
}

	if (result == false)
		printf("%s sub-test 1 passed.\n", __func__);
	else
		printf("%s sub-test 1 failed.\n", __func__);

	result = are_equal_int(NULL, &x);

	if (result == false)
		printf("%s sub-test 2 passed.\n", __func__);
	else
		printf("%s sub-test 2 failed.\n", __func__);

	result = are_equal_int(NULL, NULL);

	if (result == false)
		printf("%s sub-test 3 passed.\n", __func__);
	else
		printf("%s sub-test 3 failed.\n", __func__);
}

void test_are_equal_int_4()
{
	int x = 1;
	float y = 1;
	double z = 1;
	short w = 1;
	long u = 1;

	bool result = are_equal_int(&x, &y);

	if (result == false)
		printf("%s sub-test 1 passed.\n", __func__);
	else
		printf("%s sub-test 1 failed.\n", __func__);

	result = are_equal_int(&y, &x);

	if (result == false)
		printf("%s sub-test 2 passed.\n", __func__);
	else
		printf("%s sub-test 2 failed.\n", __func__);

	result = are_equal_int(&x, &z);

	if (result == false)
		printf("%s sub-test 3 passed.\n", __func__);
	else
		printf("%s sub-test 3 failed.\n", __func__);

	result = are_equal_int(&z, &x);

	if (result == false)
		printf("%s sub-test 4 passed.\n", __func__);
	else
		printf("%s sub-test 4 failed.\n", __func__);

	result = are_equal_int(&x, &w);

#ifdef __MACH__	
	bool expected_result = true;
#endif
#ifdef __linux__
	bool expected_result = false;
#endif

	if (result == expected_result)
		printf("%s sub-test 5 passed.\n", __func__);
	else
		printf("%s sub-test 5 failed.\n", __func__);

	result = are_equal_int(&w, &x);

	if (result == expected_result)
		printf("%s sub-test 6 passed.\n", __func__);
	else
		printf("%s sub-test 6 failed.\n", __func__);

	result = are_equal_int(&x, &u);

	if (result == true)
		printf("%s sub-test 7 passed.\n", __func__);
	else
		printf("%s sub-test 7 failed.\n", __func__);

	result = are_equal_int(&u, &x);

	if (result == true)
		printf("%s sub-test 8 passed.\n", __func__);
	else
		printf("%s sub-test 8 failed.\n", __func__);
	}
*/


int main(int argc, char *argv[], char *envp[])
{
	test_are_equal_int_1();
	test_are_equal_int_2();
	test_are_equal_int_3();
	test_are_equal_int_4();

	test_are_equal_double_1();
	test_are_equal_double_2();
	test_are_equal_double_3();
	test_are_equal_double_4();

	test_are_equal_float_1();
	test_are_equal_float_2();
	test_are_equal_float_3();
	test_are_equal_float_4();

	test_are_equal_char_1();
	test_are_equal_char_2();
	test_are_equal_char_3();
	test_are_equal_char_4();

	test_fprint_int();
	test_fprint_double();
	test_fprint_char();
	test_fprint_float();
	
	test_compare_int_1();
	test_compare_double_1();
	test_compare_float_1();
	test_compare_char_1();

	return 0;
}
