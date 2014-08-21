#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "emem.h"
#include "htable.h"


int getword(char *s, int limit, FILE *stream) {
    int c;
    char *w = s;
    assert(limit > 0 && s != NULL && stream != NULL);

    /* skip to start of word */
    while(!isalnum(c = getc(stream)) && EOF != c);

    if(EOF == c) {
        return EOF;
    } else if (--limit > 0) {
        *w++ = tolower(c);
    }

    while(--limit > 0) {
        if(isalnum(c = getc(stream))) {
            *w++ = tolower(c);
        } else if ('\'' == c) {
            limit++;
        } else {
            break;
        }
    }
    *w = '\0';
    return w - s;
}


int main(void) {
    htable h = htable_new(18143);
    char word[256];
    while (getword(word, sizeof word, stdin) != EOF) {
        htable_insert(h, word);
    }
    htable_print(h, stdout);
    htable_free(h);
    return EXIT_SUCCESS;
}
