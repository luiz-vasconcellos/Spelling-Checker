// Luiz Fernando Azevedo Vasconcellos GRR20171629
// lfav17@inf.ufpr.br

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "dicionario.h"

#define BUF_SIZE 120

int is_br_alpha(char c) {
	c = tolower(c);
	if (c >= 'a' && c <= 'z')
		return 1;

	return 0;
}

int main () {	
    init_dict();

    char c = 0;
    while((c = getchar()) != EOF) {
    	
    	while(!is_br_alpha(c) && c != EOF) {
			printf("%c",c);
			c = getchar();    		
    	}

    	char word[BUF_SIZE] = {0};
    	int i = 0;
    	while(is_br_alpha(c) && c != EOF) {
    		word[i++] = c;
    		c = getchar();
    	}

    	char lower_word[120] = {0};
    	for (int i = 0; word[i]; ++i)
    		lower_word[i] = tolower(word[i]);

    	if(!check_word(lower_word))
    		printf("[%s]",word);
    	else
    		printf("%s", word);

    	if(c != EOF)
    		printf("%c", c);
    }
    
    printf("\n");
    deinit_dict();
    return 0;
}
