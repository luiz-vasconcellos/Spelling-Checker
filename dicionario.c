// Luiz Fernando Azevedo Vasconcellos GRR20171629
// lfav17@inf.ufpr.br

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dicionario.h"

#define DICT_PATH "/usr/share/dict/brazilian"

// Array of C-strings that will hold dict in memory
static char **pp_words = 0;
// Number of words in dict
static int i_nwords = 0;

int comp(const void *a, const void *b);

int init_dict() {
    // Open file and check its results
    FILE *dict = fopen(DICT_PATH, "r");
    if( !dict ) {
        fprintf(stderr, "Falha ao abrir o dicionario\n");
        return -1;
    }

    // Calculating the number of words in file
    i_nwords = 0;
    char *line = NULL;
    size_t len;
    while(getline(&line, &len, dict) != -1) i_nwords++;

    pp_words = malloc(i_nwords * sizeof *pp_words);
    if( !pp_words ) {
        fprintf(stderr, "Falha ao alocar memoria para dicionario\n");
        return -1;
    }
    
    // Now read the words for real
    rewind(dict);
    for( int i=0; i < i_nwords; ++i ) {
        getline(&line, &len, dict); // with trailing \n

        /* We can allocate it all at once if the program
           needs to run faster */
        size_t line_len = strlen(line);
        pp_words[i] = malloc(line_len * sizeof *pp_words[i]);
        if( !pp_words[i] ) {
            fprintf(stderr, "Falha ao alocar memoria para a %i-esima linha do dicionario", i);
            return -1;
        }

        /* 
           getline reads 120 characters, here we cut after the last 
           meaningful one and use the lower case version
        */
        line[line_len-1] = '\0';
        line[0] = to_br_lower(line[0]);
        strcpy(pp_words[i], line);
    }

    // Need to sort dict after transforming all to lower case
    qsort(pp_words, i_nwords, sizeof(char*), comp);

    // Close file and return
    fclose(dict);
    return 0;
}

/*
    Free every char* string and then
    free the array of chars
*/
void deinit_dict() {
    for( int i=0; i < i_nwords; ++i )
        free(pp_words[i]);
    free(pp_words);

    pp_words = NULL; // Good practices
}

// Just an API for programmers
int check_word( char *str ) {
    char *res = bsearch(&str, pp_words, i_nwords, sizeof(char*), comp);
    return (res != NULL);
}

// Comp function for sorting
int comp(const void *a, const void *b)  { 
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
} 


/*
    Function that gives a rough idea for alpha
    characters in the extended ASCII table; may
    have false positives
*/
int is_br_alpha( char c ) {
    c = tolower(c);
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c > -65 && c < 0)
        return 1;

    return 0;
}

// Return lowercase for extended ASCII table
char to_br_lower( char c ) {
    if( c > -65 && c < -36 )
        return c + 32;
    else
        return tolower(c);
}
