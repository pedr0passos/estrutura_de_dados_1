#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// estrutura do n� 
typedef struct no {
    int info;
    struct no *prox;
}NoLista;

//fun��es:

//fun��o que cria linha separadora
void linha() {

    printf("\n--------------------------------------------------\n");

}
//fun��o que cria lista
void criar_lista (NoLista **l) {

    *l = NULL;

}
//fun��o que verifica se a lista est� vazia
int lista_vazia (NoLista **l) {

    if ( *l == NULL ) {

        return 1;

    } else {

        return 0;

    }

}

//fun��o que insere uma informa��o na lista
void insere_inicio (NoLista **l, int v ) {

    NoLista*novo_item = malloc(sizeof(NoLista));

    if ( novo_item!=NULL) {

        novo_item->info = v;
        novo_item->prox = *l;
        *l = novo_item;

    } else {

        printf("N�o foi poss�vel alocar espa�o!");

    }

}

//fun��o que imprime a lista
void imprime (NoLista **l) {
    
    if (!lista_vazia(l)) {
        NoLista *p;
        for ( p = *l; p != NULL; p = p->prox) {
            printf("N�mero: %d\n", p->info);
        }
    } else {
        printf("Lista est� vazia.");
    }
}
//fun��o que faz busca pela lista
NoLista *busca (NoLista **l, int v) {
        NoLista *p;
        linha();
        for ( p = *l; p != NULL; p = p->prox) {
            if (p->info == v) {
                return p;
            }
        }
        return NULL;
}

//fun��o que remove um item da lista

void remover_elemento (NoLista **l, int v) {
    NoLista *p, *ant = NULL;
    for ( p = *l; p !=NULL && p->info != v; p = p->prox) { // atribuindo ant ao valor anterior a p
        ant = p;
    } 
    if ( ant == NULL ) {    // retirando no primeiro termo 
        *l = p->prox;
    } else {
        ant->prox = p->prox;
    } 
    free(p);
}

//fun��o que libera a lista

void libera_lista (NoLista **l) {
    NoLista *p, *temp;
    for ( p = *l; p != NULL; p = p->prox ) {
        temp = p->prox;
        free(p);
        printf("Lista Vazia");
    } 
    *l = NULL;
}

//fun��o que insere uma informa��o numa ordem especifica ( insere uma informa��o ordenada ) 

void insere_ordenado (NoLista **l, int v) {
    NoLista *p, *ant = NULL;
    NoLista *novo = (NoLista*)malloc(sizeof(NoLista));

    novo->info = v; 
    
    if ( !lista_vazia(l) ) {

        printf("\nIF\n");


        for ( p = *l; p != NULL && p->info < v; p = p->prox ) {
            ant = p;
        }

        if ( ant == NULL ) {            // QUANDO PRECISA INSERIR NO COME�O

            novo->prox = p;
            *l = novo;

        } else {

            ant->prox = novo;
            novo->prox  = p;

        }

    } else {

        printf("\nELSE\n");
        novo->prox = *l;
        *l = novo;

    }

}

int main () {
setlocale(LC_ALL,"portuguese");
//variaveis
NoLista *lista;
int w=0, opcao, valor;
//cria��o da lista
criar_lista(&lista);
//limpa terminal
system("cls");
//menu do programa
    while ( w == 0 ) {
    printf("\nMENU:\n");
    printf("1 - Ler um novo n�mero\n");
    printf("2 - Imprimir lista\n");
    printf("3 - Buscar n�mero\n");
    printf("4 - Remover um elemento.\n");
    printf("5 - Esvaziar lista\n");
    printf("6 - Inserir Ordenado\n");
    printf("7 - Sair\n");
    printf("Op��o: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        system("cls");
        linha();
        printf("Digite um n�mero para inserir na lista: ");
        scanf("%d", &valor);
        linha();
        insere_inicio(&lista, valor);
        break;
    case 2:
        system("cls");
        linha();
        imprime(&lista);
        linha();
        break;
    case 3:
        system("cls");
        linha();
        printf("Digite um n�mero para fazer busca: ");
        scanf("%d", &valor);
        linha();
        printf("Endere�o: %p ( O N�mero est� na lista! )", busca(&lista, valor));
        linha();
        break;
    case 4:
        system("cls");
        linha();
        printf("Digite o n�mero que deseja remover: ");
        scanf("%d", &valor);
        linha();
        remover_elemento(&lista, valor);
        printf("\n------Lista com Elemento Removido------");
        imprime(&lista);
        break;
    case 5:
        system("cls");
        linha();
        libera_lista (&lista);
        linha();
        break;
    case 6:
        system("cls");
        linha();
        printf("Digite o valor para inserir ordenadamente: ");
        scanf("%d", &valor);
        insere_ordenado(&lista, valor);
        break;
    case 7:
        w = 1;
        break;
    default:
        break;
    }
}
return 0;
}