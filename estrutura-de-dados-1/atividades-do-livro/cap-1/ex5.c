// Crie um programa que leia uma variável e crie dois vetores dinâmicos, um com o tamanho lido e outro com o dobro desse tamanho. Preencha esses vetores respectivamente com potências de 2 e potências de 3.
// a) Crie uma variável inteira e dois ponteiros do tipo inteiro.
// b) Pergunte ao usuário o tamanho do vetor dinâmico e leia esse valor na variável inteira.
// c) Aloque dinamicamente os dois vetores usando a função malloc.
// d) Faça um laço de repetição para preencher o primeiro vetor com potências de 2.
// e) Faça um segundo laço de repetição para preencher o outro vetor com potências de 3.
// f) Não se esqueça de usar a biblioteca math.h para poder usar o cálculo de potência (pow).

#include <stdio.h>;
#include <stdlib.h>;
#include <math.h>;

int main() {
    int tam;
    int *ptr_1, *ptr_2;

    printf("\n\nQual sera o tamanho do vetor dinamico? ");
    scanf("%d", &tam);
    ptr_1 = (int *)malloc(sizeof(int) * tam);
    ptr_2 = (int *)malloc(sizeof(int) * (tam * 2));

    for(int i = 0; i < tam; i++) {
        ptr_1[i] = pow(2, i);
        printf("%d ", ptr_1[i]);
    }
    printf("\n\n");

    for(int i = 0; i < (tam * 2); i++) {
        ptr_2[i] = pow(3, i);
        printf("%d ", ptr_2[i]);
    }
    printf("\n\n");

    free(ptr_1);
    free(ptr_2);

    system("pause");
}