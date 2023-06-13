// Quando um livro é devolvido na Biblioteca do Unicesumar, o funcionário colocado o livro em cima de uma pilha de livros na mesa ao lado da recepção. O auxiliar de bibliotecário pega o livro do topo da pilha, verifica o seu código e leva-o para o seu devido local no acervo.
// No atual sistema de informação, é possível verificar se o livro está disponível ou se está emprestado. Entretanto o livro que acabou de ser devolvido ainda não se encontra na prateleira, pois existe um intervalo de tempo entre a devolução do mesmo e o momento em que ele é guardado na estante.
// A sugestão do departamento de TI é de criar um programa que faça o controle na pilha, assim, pode-se verificar se o livro ainda não foi guardado e qual a sua posição dentro da pilha de livros que aguardam ao lado da recepção.
// a) Crie uma estrutura para a pilha de livros. Lembre-se de que ela tem que ter um vetor para armazenar os dados (código, nome do livro e autor) e dois números inteiros, um para controlar o início e outro o final da pilha.
// b) Define a variável que será um vetor do tipo pilha de livros.
// c) Faça uma função de empilhamento, lembrando-se de verificar se a pilha atingiu o tamanho máximo de livros (a mesa não aguenta muito meso).
// d) Crie uma função para desempilhamento de livros. Não se esqueça de que é necessário verificar se ainda existem livros para ser guardados.
// e) Elabore uma função que apresente na tela a lista de todos os livros que se encontram empilhados ao lado da recepção.

#include <stdio.h>
#include <stdlib.h>

#define tamanho 3
#define tamanho_nome_autor 50

struct dados_do_livro {
    int codigo;
    char nome[tamanho_nome_autor];
    char autor[tamanho_nome_autor];
};

struct pilha_de_livros {
    struct dados_do_livro livro[tamanho];
    int ini;
    int fim;
};

struct pilha_de_livros pilha;
int op = -1;

void empilhar();
void desempilhar();
void menu_opcoes();
void mostrar_pilha();

int main() {
    pilha.ini = 0;
    pilha.fim = 0;

    while (op != 0) {
        system("cls");
        mostrar_pilha();
        menu_opcoes();
        switch(op) {
            case 1:
                empilhar();
                break;
            case 2:
                desempilhar();
                break;
        }
    }
}

void menu_opcoes() {
    printf("\n\nEscolha uma opcao:\n");
    printf("1 - Adicionar livro na pilha\n");
    printf("2 - Remover livro da pilha\n");
    printf("0 - Sair\n\n");
    scanf("%d", &op);
    fflush(stdin);
}

void mostrar_pilha() {
    for (int i = 0; i < tamanho; i++) {
        printf("{ Codigo: %d, Nome: %s, Autor: %s }\n", pilha.livro[i].codigo, pilha.livro[i].nome, pilha.livro[i].autor);
    }
    printf("\n\n");
}

void empilhar() {
    if (pilha.fim == tamanho) {
        printf("A pilha esta cheia! Tente novamente mais tarde.");
        system("pause");
    } else {
        printf("Qual o codigo do livro que deseja adicionar? ");
        scanf("%d", &pilha.livro[pilha.fim].codigo);
        fflush(stdin);
        printf("E qual o nome do livro? ");
        scanf("%s", pilha.livro[pilha.fim].nome);
        fflush(stdin);
        printf("E o autor do livro? ");
        scanf("%s", pilha.livro[pilha.fim].autor);
        fflush(stdin);
        printf("\n\n");
        pilha.fim++;
    }
}

void desempilhar() {
    if (pilha.ini == pilha.fim) {
        printf("A pilha ja esta vazia!");
        system("pause");
    } else {
        pilha.livro[pilha.fim - 1].codigo = 0;

        for(int i = 0; i < tamanho_nome_autor; i++) {
            pilha.livro[pilha.fim - 1].nome[i] = '\0';
            pilha.livro[pilha.fim - 1].autor[i] = '\0';
        }

        pilha.fim--;
    }
}