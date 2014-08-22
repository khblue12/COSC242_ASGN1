#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "emem.h"

struct htablerec {
    int capacity;
    int num_keys;

    char **keys;
    int *freq;
};

/* Magically converts a word into a number */
static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;

    while(*word != '\0') {
        result = (*word++ + 31 * result);
    }

    return result;
}

/* Initialise Data */
htable htable_new(int capacity) {
    int i = 0;
    htable ht = emalloc(sizeof *ht);

    ht->capacity = capacity;
    ht->num_keys = 0;

    /* Allocate memory to arrays */
    ht->freq = emalloc(capacity * sizeof ht->freq[0]);

    ht->keys = emalloc(capacity * sizeof ht->keys);

   /* Initilse arrays with default values */
   for(i = 0; i < capacity; i++) {
       ht->freq[i] = 0;
   }

   return ht;
}

/* Free up the memory when done */
void htable_free(htable h) {
    int i = 0;

    for(i = 0; i < h->capacity; i++) {
        free(h->keys[i]);
    }
    free(h->keys);
    free(h->freq);
    free(h);
}


/* Insert a string into the table
 * Returns the number of times the str
 * has been added to the table
 */
int htable_insert(htable h, char *str) {
    unsigned int k = htable_word_to_int(str) % h->capacity;
    int trys = 0;

    /* Try to find an empty space or the same key */
    while(trys < h->capacity) {
        /* If space empty add key to that space */
        if(h->freq[k] == 0) {
            h->keys[k] = emalloc((strlen(str)+1) * sizeof h->keys[0] );
            strcpy(h->keys[k], str);
            h->freq[k] = 1;
            h->num_keys = h->num_keys + 1;
            return 1;
        }

        /* Else if the string is already in table increase freq */
        if(strcmp(h->keys[k], str) == 0) {
            h->freq[k] = h->freq[k]+1;
            return h->freq[k];
        }

        /* Else try another position in table */
        k = (k+1)%h->capacity;
        ++trys;
    }

    /* if table full */
    return 0;
}


int htable_search(htable h, char *str) {
    unsigned int k  = htable_word_to_int(str) % h->capacity;
    int trys = 0;

    while(trys < h->capacity ) {
        /* Not in table */
        if(h->freq[k] == 0) return 0;
        if(strcmp(h->keys[k], str) == 0)
            return h->freq[k];
        k = (k+1)%h->capacity;
        ++trys;
    }
    return 0;
}


/* Print the table to the specified stream */
void htable_print(htable h, FILE *stream) {
    int i = 0;
    if(h->num_keys > 0) {
        fprintf(stream,"n  FREQ       KEY\n");
        fprintf(stream,"==|====|=========\n");
        for(i = 0; i < h->capacity; i++) {
            if(h->freq[i] != 0) 
                fprintf(stream, "%d   %d       %s\n", i, h->freq[i], h->keys[i]);
        }
    } else {
        fprintf(stream, "Empty Table\n");
    }
}
