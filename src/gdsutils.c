#include "gdsutils.h"

#include <math.h>

const float EPSILON_F = 1E-8;
const double EPSILON_D = 1E-8;

bool are_equal_int(void *px, void *py)
{
    bool result = false;

    if (px && py) 
        result = (*((int *)px) == *((int *)py));

    return result;
}

bool are_equal_char(void *px, void *py)
{
    bool result = false;

    if (px && py) 
        result = (*((char *)px) == *((char *)py));

    return result;
}

bool are_equal_float(void *px, void *py)
{
    bool result = false;

    if (px && py) {
		float fx = *((float *)px);
		float fy = *((float *)py);
        result = fabs(fx - fy) < EPSILON_F;
	}

    return result;
}

bool are_equal_double(void *px, void *py)
{
    bool result = false;

    if (px && py) {
		double dx = *((double *)px);
		double dy = *((double *)py);
        result = fabs(dx - dy) < EPSILON_D;
	}

    return result;
}

int fprint_int(FILE *fp, void *px)
{
    int rv = -1; /* return value. */

    if (fp && px)
        rv = fprintf(fp, "%d", *(int *)px);

    return rv;
}

int fprint_char(FILE *fp, void *px)
{
    int rv = -1; /* return value. */

    if (fp && px)
        rv = fprintf(fp, "%c", *(char *)px);

    return rv;
}

int fprint_float(FILE *fp, void *px)
{
    int rv = -1; /* return value. */

    if (fp && px)
        rv = fprintf(fp, "%f", *(float *)px);

    return rv;
}

int fprint_double(FILE *fp, void *px)
{
    int rv = -1; /* return value. */

    if (fp && px)
        rv = fprintf(fp, "%f", *(double *)px);

    return rv;
}

int print_int(void *px)    { return fprint_int(stdout, px); }
int print_char(void *px)   { return fprint_char(stdout, px); }
int print_float(void *px)  { return fprint_float(stdout, px); }
