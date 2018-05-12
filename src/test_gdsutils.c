#include "gdsutils.h"

void test_are_equal_int_1()
{
    int x = 1;
    int y = 1;

    bool result = are_equal_int(&x, &y);

    if (result == true)
        printf("%s passed.\n", __FUNCTION__);
    else
        printf("%s failed.\n", __FUNCTION__);
}

void test_are_equal_int_2()
{
    int x = 1;
    int y = 2;

    bool result = are_equal_int(&x, &y);

    if (result == false)
        printf("%s sub-test 1 passed.\n", __FUNCTION__);
    else
        printf("%s sub-test 1 failed.\n", __FUNCTION__);

    result = are_equal_int(&y, &x);

    if (result == false)
        printf("%s sub-test 2 passed.\n", __FUNCTION__);
    else
        printf("%s sub-test 2 failed.\n", __FUNCTION__);
}

void test_are_equal_int_3()
{
    int x = 1;

    bool result = are_equal_int(&x, NULL);

    if (result == false)
        printf("%s sub-test 1 passed.\n", __FUNCTION__);
    else
        printf("%s sub-test 1 failed.\n", __FUNCTION__);

    result = are_equal_int(NULL, &x);

    if (result == false)
        printf("%s sub-test 2 passed.\n", __FUNCTION__);
    else
        printf("%s sub-test 2 failed.\n", __FUNCTION__);

    result = are_equal_int(NULL, NULL);

    if (result == false)
        printf("%s sub-test 3 passed.\n", __FUNCTION__);
    else
        printf("%s sub-test 3 failed.\n", __FUNCTION__);
}

void test_are_equal_int_4()
{
    int x = 1;
    float y = 1;
	double z = 1;
	short w = 1;
	long u =1;

    bool result = are_equal_int(&x, &y);

    if (result == false)
        printf("%s sub-test 1 passed.\n", __FUNCTION__);
    else
        printf("%s sub-test 1 failed.\n", __FUNCTION__);

    result = are_equal_int(&y, &x);

    if (result == false)
        printf("%s sub-test 2 passed.\n", __FUNCTION__);
    else
        printf("%s sub-test 2 failed.\n", __FUNCTION__);

    result = are_equal_int(&x, &z);

    if (result == false)
        printf("%s sub-test 3 passed.\n", __FUNCTION__);
    else
        printf("%s sub-test 3 failed.\n", __FUNCTION__);

    result = are_equal_int(&z, &x);

    if (result == false)
        printf("%s sub-test 4 passed.\n", __FUNCTION__);
    else
        printf("%s sub-test 4 failed.\n", __FUNCTION__);

    result = are_equal_int(&x, &w);

    if (result == false)
        printf("%s sub-test 5 passed.\n", __FUNCTION__);
    else
        printf("%s sub-test 5 failed.\n", __FUNCTION__);

    result = are_equal_int(&w, &x);

    if (result == false)
        printf("%s sub-test 6 passed.\n", __FUNCTION__);
    else
        printf("%s sub-test 6 failed.\n", __FUNCTION__);

    result = are_equal_int(&x, &u);

    if (result == true)
        printf("%s sub-test 7 passed.\n", __FUNCTION__);
    else
        printf("%s sub-test 7 failed.\n", __FUNCTION__);

    result = are_equal_int(&u, &x);

    if (result == true)
        printf("%s sub-test 8 passed.\n", __FUNCTION__);
    else
        printf("%s sub-test 8 failed.\n", __FUNCTION__);
}

int main(int argc, char *argv[], char *envp[])
{
    test_are_equal_int_1();
    test_are_equal_int_2();
    test_are_equal_int_3();
    test_are_equal_int_4();

    return 0;
}

