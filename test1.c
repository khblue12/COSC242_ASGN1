#include <stdio.h>
#include <stdlib.h>
#include "htable.h"

int main(void) {
    int num = 0;
    htable cool = htable_new(10);
    printf("Adding some words\n");

    num = htable_insert(cool, "Cool");
    if(num != 0)
        printf("..added success\n");
    else
        printf(".. failed to add\n");

    num = htable_insert(cool, "fre");
    if(num != 0)
        printf("..added success\n");
    else
        printf(".. failed to add\n");
    num = htable_insert(cool, "Cool");
    if(num != 0)
        printf("..added success\n");
    else
        printf(".. failed to add\n");
    num = htable_insert(cool, "sam");
    if(num != 0)
        printf("..added success\n");
    else
        printf(".. failed to add\n");
    num = htable_insert(cool, "john");
    if(num != 0)
        printf("..added success\n");
    else
        printf(".. failed to add\n");
    num = htable_insert(cool, "john");
    if(num != 0)
        printf("..added success\n");
    else
        printf(".. failed to add\n");
    num = htable_insert(cool, "sam");
    if(num != 0)
        printf("..added success\n");
    else
        printf(".. failed to add\n");
    num = htable_insert(cool, "billy");
    if(num != 0)
        printf("..added success\n");
    else
        printf(".. failed to add\n");
    num = htable_insert(cool, "billy");
    if(num != 0)
        printf("..added success\n");
    else
        printf(".. failed to add\n");
    num = htable_insert(cool, "billy");
    if(num != 0)
        printf("..added success\n");
    else
        printf(".. failed to add\n");
    num = htable_insert(cool, "blly");
    if(num != 0)
        printf("..added success\n");
    else
        printf(".. failed to add\n");
    num = htable_insert(cool, "bly");
    if(num != 0)
        printf("..added success\n");
    else
        printf(".. failed to add\n");
    num = htable_insert(cool, "by");
    if(num != 0)
        printf("..added success\n");
    else
        printf(".. failed to add\n");
    num = htable_insert(cool, "billy");
    if(num != 0)
        printf("..added success\n");
    else
        printf(".. failed to add\n");
    num = htable_insert(cool, "illy");
    if(num != 0)
        printf("..added success\n");
    else
        printf(".. failed to add\n");
    num = htable_insert(cool, "lly");
    if(num != 0)
        printf("..added success\n");
    else
        printf(".. failed to add\n");
    num = htable_insert(cool, "billy");
    if(num != 0)
        printf("..added success\n");
    else
        printf(".. failed to add\n");
    num = htable_insert(cool, "silly");
    if(num != 0)
        printf("..added success\n");
    else
        printf(".. failed to add\n");
    num = htable_insert(cool, "silly");
    if(num != 0)
        printf("..added success\n");
    else
        printf(".. failed to add\n");


    htable_print(cool, stdout);


    printf("Searching for 'Cool' found %d\n", htable_search(cool,"Cool"));
    printf("Searching for 'silly' found %d\n", htable_search(cool,"silly"));
    printf("Searching for 'lly' found %d\n", htable_search(cool,"lly"));

    htable_free(cool);
    return EXIT_SUCCESS;
}
