// Luiz Fernando Azevedo Vasconcellos GRR20171629
// lfav17@inf.ufpr.br

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dicionario.h"

#define DICT_PATH "/usr/share/dict/brazilian"

// Array of C-strings that will hold dict in memory
char **pp_words = 0;
// Number of words in dict
int i_nwords = 0;

// Basic binary search algorithm
int b_search(char *, int, int);

int init_dict() {
    // Open file and check its results
    FILE *dict = fopen(DICT_PATH, "r");
    if(!dict) {
        fprintf(stderr, "Falha ao abrir o dicionario\n");
        return -1;
    }

    // Calculating the number of words in file
    i_nwords = 0;
    char *line = NULL;
    size_t len;
    while(getline(&line, &len, dict) != -1) i_nwords++;

    pp_words = malloc(i_nwords * sizeof *pp_words);
    if(!pp_words) {
        fprintf(stderr, "Falha ao alocar memoria para dicionario\n");
        return -1;
    }
    
    // Now read the words for real
    rewind(dict);
    for(int i=0; i < i_nwords; ++i) {
        getline(&line, &len, dict); // with trailing \n

        /* We can allocate it all at once if the program
           needs to run faster */
        size_t line_len = strlen(line);
        pp_words[i] = malloc(line_len * sizeof *pp_words[i]);
        if(!pp_words[i]) {
            fprintf(stderr, "Falha ao alocar memoria para a %i-esima linha do dicionario", i);
            return -1;
        }

        line[line_len-1] = '\0';
        strcpy(pp_words[i], line);
    }

    fclose(dict);
    return 0;
}

void deinit_dict() {
    for(int i=0; i < i_nwords; ++i)
        free(pp_words[i]);
    free(pp_words);
    pp_words = 0;
}

int check_word(char *str) {
    return b_search(str, 0, i_nwords-1);
    return 0;
}

int b_search(char *str, int a, int b) {
    if(a == b)
        return (strcmp(str, pp_words[a]) == 0);

    int mid = (a + b) / 2;
    int cmp = strcmp(str, pp_words[mid]);

    if(cmp == 0)
        return 1;
    else if(cmp < 0)
        return b_search(str, a, mid);
    else
        return b_search(str, mid+1, b);
}

int is_br_alpha(char c) {
    c = tolower(c);
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c > -65 && c < 0)
        return 1;

    return 0;
}

char to_br_lower(char c) {
    if(c > -65 && c < -36)
        return c + 32;
    else return tolower(c);
}