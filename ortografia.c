// Luiz Fernando Azevedo Vasconcellos GRR20171629
// lfav17@inf.ufpr.br

#include <stdio.h>
#include "dicionario.h"

int main () {
    init_dict();
    printf("%i \n", check_word("batataasdasd"));
    deinit_dict();
    return 0;
}
