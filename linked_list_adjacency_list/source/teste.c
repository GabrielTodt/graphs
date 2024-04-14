#include <stdio.h>

void altera_valor(int *x){
    *x = 10;
}


int main(int argc, char const *argv[])
{   
    int valor = 10;
    altera_valor(&valor);
    printf("%d", valor);
    return 0;
}
