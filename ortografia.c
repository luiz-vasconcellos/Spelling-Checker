// Luiz Fernando Azevedo Vasconcellos GRR20171629
// lfav17@inf.ufpr.br

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "dicionario.h"

#define BUF_SIZE 120

int main () {
    init_dict();

    char c = 0;
    while( (c = getchar() ) != EOF ) {

        // Read non alpha chars
        while( !is_br_alpha(c) && c != EOF  ) {
            printf("%c",c);
            c = getchar();
        }

        // Read a word
        char word[BUF_SIZE] = {0};
        int i = 0;
        while( is_br_alpha(c) && c != EOF ) {
            word[i++] = c;
            c = getchar();
        }

        // Get the lower case version of the word
        char lower_word[BUF_SIZE] = {0};
        for ( int i = 0; word[i]; ++i )
            lower_word[i] = to_br_lower(word[i]);

        // Handle the output
        if( !check_word(lower_word)  &&  c != EOF )
            printf("[%s]",word);
        else
            printf("%s", word);	
    	
        if( c != EOF )
            printf("%c", c);
    }
    
    // Wraps up
    printf("\n");
    deinit_dict();
    return 0;
}

