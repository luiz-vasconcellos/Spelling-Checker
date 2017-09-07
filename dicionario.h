// Luiz Fernando Azevedo Vasconcellos GRR20171629
// lfav17@inf.ufpr.br

#ifndef DICIONARIO_H
#define DICIONARIO_H

/*
 * Loads words from dictionary into memory.
 * Return -1 if there was an error, 0 otherwise.
 */
int init_dict();

/* Clean up dictionary related functions. */
void deinit_dict();

/* Return 1 if word is in dictionary, 0 otherwise. */
int check_word(char *str);

#endif
