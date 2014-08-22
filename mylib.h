#ifndef MYLIB_H_
#define MYLIB_H_
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
extern int getword(char *s, int limit, FILE *stream);
extern void *emalloc(size_t);
extern void *erealloc(void *, size_t);
#endif
