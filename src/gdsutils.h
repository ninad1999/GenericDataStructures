#ifndef _GDSUTILS_H_
#define _GDSUTILS_H_

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Functions to test equality of various data types. */
bool are_equal_int(void *px, void *py);
bool are_equal_char(void *px, void *py);
bool are_equal_float(void *px, void *py);
bool are_equal_double(void *px, void *py);

int fprint_int(FILE *, void *px);
int fprint_char(FILE *, void *px);
int fprint_float(FILE *, void *px);
int fprint_double(FILE *, void *px);

int print_int(void *px);
int print_char(void *px);
int print_float(void *px);
int print_double(void *px);

int compare_int(void *px, void *py);
int compare_double(void *px, void *py);
int compare_float(void *px, void *py);
int compare_char(void *px, void *py);

#endif

