// Uma agência bancária quer inovar seu atendimento, criando mais conforto para seus clientes. Para isso, foram colocadas diversas cadeiras na recepção do banco. Quando um cliente chega, o atendente lança no computador o seu nome e o horário que chegou. Assim que um caixa fica livre, a recepcionalista olha no sistema e chama o primeiro cliente da fila. Dessa forma, é possível que os clientes esperem confortavelmente sentados pelo seu atendimento, não importando o local onde se encontrem dentro da agência bancária.
// a) Faça uma estrutura para o controle da fila. Você precisa guardar o nome e a hora que o cliente chegou. Use um vetor para armazenar os dados e dois números inteiros, um para controlar o início e outro o final da fila.
// b) Defina a variável que será um vetor do tipo fila de clientes.
// c) Crie uma função enfileirar, lembrando que é preciso verificar se há espaço na fila (o número de cadeiras na recepção é limitado).
// d) Elabore a função desenfileirar cliente, não se esqueça de que é necessário verificar se ainda existem clientes para serem atendidos.
// e) Faça uma função que apresente na tela a lista de todos os clientes que estão aguardando atendimento na recepção.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 3

struct cliente_struct {
    char nome[30];
    char hora[6];
};

struct fila_de_clientes {
    struct cliente_struct cliente[tamanho];
    int ini;
    int fim;
};

struct fila_de_clientes fila;
int op = -1;

void enfileirar();
void desenfileirar();
void mostrar_fila();
void mostrar_menu();

int main() {
    fila.ini = 0;
    fila.fim = 0;
    while(op != 0) {
        system("cls");
        mostrar_fila();
        mostrar_menu();
        switch(op) {
            case 1:
                enfileirar();
                break;
            case 2:
                desenfileirar();
                break;
        }
    }
}

void mostrar_fila() {
    for (int i = 0; i < tamanho; i++) {
        printf("{ Nome: %s, Hora: %s}\n", fila.cliente[i].nome, fila.cliente[i].hora);
    }
    printf("\n");
}

void mostrar_menu() {
    printf("Escolha uma operacao:\n");
    printf("1 - Enfileirar\n");
    printf("2 - Desenfileirar\n");
    printf("0 - Sair\n\n");
    scanf("%d", &op);
}

void enfileirar() {
    if (fila.fim == tamanho) {
        printf("A fila ja esta cheia!\n");
        system("pause");
    } else {
        printf("Nome: ");
        scanf("%s", fila.cliente[fila.fim].nome);
        fflush(stdin);
        printf("Hora (ex 15:32): ");
        scanf("%s", fila.cliente[fila.fim].hora);
        fflush(stdin);
        fila.fim++;
    }
}

void desenfileirar() {
    if (fila.fim == fila.ini) {
        printf("A fila ja esta vazia!\n");
        system("pause");
    } else {
        for (int i = 0; i < tamanho; i++) {
            strcpy(fila.cliente[i].nome, fila.cliente[i + 1].nome);
            strcpy(fila.cliente[i].hora, fila.cliente[i + 1].hora);
        }
        strcpy(fila.cliente[fila.fim].nome, "");
        strcpy(fila.cliente[fila.fim].hora, "");
        printf("\n");
        fila.fim--;
    }
}