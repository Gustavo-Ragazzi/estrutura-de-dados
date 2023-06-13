// Faça um pequeno programa para testar seus conhecimentos sobre ponteiros e alocação dinâmica na memória.
// a) Defina um ponteiro do tipo inteiro.
// b) Faça alocação dinâmica para o ponteiro recém-criado.
// c) Preencha a memória com o valor 42.
// d) Imprima o endereço do ponteiro na memória e o valor contido nele.

#include <stdio.h>;
#include <stdlib.h>;

main() {
    int *ptr;
    ptr = (int *) malloc(sizeof(int));
    *ptr = 42;

    printf("Endereco: %p\nValor: %d\n\n", ptr, *ptr);

    free(ptr);

    system("pause");
}