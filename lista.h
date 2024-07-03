#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int matricula;
    char nome[60];
    char escola[30];
    char titulacao[30];
    char tipoDeContrato[30];
}Professor;

typedef struct{
    int tamanho;
    Professor *array;
    int indiceOcupacao;
} ListaVetor;

void carregarProf(Professor * const prof, char * const str){
    char *pt = NULL;

     pt = strtok(str,";");
     prof->matricula = atoi(str);

     pt = strtok(NULL,";");
     strcpy(prof->nome,pt);

     pt = strtok(NULL,";");
     strcpy(prof->escola,pt);

     pt = strtok(NULL,";");
     strcpy(prof->titulacao,pt);

     pt = strtok(NULL,";");
     strcpy(prof->tipoDeContrato,pt);
}
// Inicialização dos dados da Lista
void inicializarDadosLista(int tamanho, ListaVetor *const lista){
    if(tamanho<=0){
        printf("Tamanho da lista não pode ser menor ou igual a 0");
        return;
    }
    lista->array=malloc(tamanho*sizeof(Professor));
    if(lista->array==NULL){
        printf("\nLista não pode ser criada\n");
        return;
    }
    lista->tamanho=tamanho;
    lista->indiceOcupacao=-1;
}

// Mostrar dados da struct professor
void mostrarDadosProfessor(Professor const * const prof)
{
printf("\nProfessor: \n");
printf("Matricula: %d ", prof->matricula);
printf("Nome: %s ", prof->nome);
printf("Escola: %s ", prof->escola);
printf("Titulação: %s ", prof->titulacao);
printf("Tipo de Contrato: %s\n", prof->tipoDeContrato);
}
// Verificar se lista esta cheia

int verificarListaCheia(ListaVetor const *const lista){
    return((lista->indiceOcupacao+1) == lista->tamanho);
}

// Verificar se lista esta vazia
int verificarListaVazia(ListaVetor const *const lista){
    return(lista->indiceOcupacao == -1);
}


// Mostrar dados existentes na lista
void imprimirLista(ListaVetor *const lista){
    printf("Lista: {");
    for(int i=0; i<=lista->indiceOcupacao; i++){
        if(i<lista->indiceOcupacao){

            printf("[%d, ", (lista->array+i)->matricula);
            printf("%s, ", (lista->array+i)->nome);
            printf("%s, ", (lista->array+i)->escola);
            printf("%s, ", (lista->array+i)->titulacao);
            printf("%s], \n", (lista->array+i)->tipoDeContrato);

        }
        else {
            printf("[%d, ", (lista->array+i)->matricula);
            printf("%s, ", (lista->array+i)->nome);
            printf("%s, ", (lista->array+i)->escola);
            printf("%s, ", (lista->array+i)->titulacao);
            printf("%s] \n", (lista->array+i)->tipoDeContrato);

        }
    }
    printf("}\n");
}

void inserirElementoNoFinal(Professor *const prof, ListaVetor *const lista){
    if(verificarListaCheia(lista)){
        printf("Fila está cheia!\n");
        return;
    }
    lista->indiceOcupacao++;
    (lista->array+lista->indiceOcupacao)->matricula = prof->matricula;
    strcpy((lista->array+lista->indiceOcupacao)->nome, prof->nome);
    strcpy((lista->array+lista->indiceOcupacao)->escola, prof->escola);
    strcpy((lista->array+lista->indiceOcupacao)->titulacao, prof->titulacao);
    strcpy((lista->array+lista->indiceOcupacao)->tipoDeContrato,prof->tipoDeContrato);
}

// Mostrar dados da lista
void mostrarDadosLista(ListaVetor *const lista){
    // Mostrar os dados de uma lista
    printf("\n*******************\n");
    printf("    DADOS DA LISTA  \n");
    printf("\nTamanho da lista: %d\n",lista->tamanho);
    printf("Quantidade de elementos: %d\n",lista->indiceOcupacao+1);
    imprimirLista(lista);
    printf("\n*******************\n");

}

Professor retirarFinalLista(ListaVetor *const lista){
    if(verificarListaVazia(lista)){
        printf("\nLista está vazia\n");
        exit(1);
    }

    if(lista->indiceOcupacao == 0){
        lista->indiceOcupacao = -1;
        exit(1);
    }
    Professor prof = *(lista->array + lista->indiceOcupacao);
    lista->indiceOcupacao--;
    return prof;
}

Professor acessarFinalLista(ListaVetor const * const lista){
    if(verificarListaVazia(lista)){
        printf("Lista está vazia");
        exit(1);
    }

    return *(lista->array + lista->indiceOcupacao);
}

void inserirElementoNoInicio(Professor *const prof, ListaVetor *const lista){
    if(verificarListaCheia(lista)){
        printf("Fila está cheia!\n");
        return;
    }
    lista->indiceOcupacao++;
    int aux = lista->indiceOcupacao;
    while(aux>0){
        *(lista->array+aux)=*(lista->array+(aux-1));
        aux--;
    }
    (lista->array + 0)->matricula= prof->matricula;
    strcpy((lista->array+0)->nome, prof->nome);
    strcpy((lista->array+0)->escola, prof->escola);
    strcpy((lista->array+0)->titulacao, prof->titulacao);
    strcpy((lista->array+0)->tipoDeContrato, prof->tipoDeContrato);
}

Professor retirarInicioLista(ListaVetor *const lista){
    if(verificarListaVazia(lista)){
        printf("\nLista está vazia\n");
        exit(1);
    }
    lista->indiceOcupacao--;
    Professor prof = *(lista->array + 0);
    if(lista->indiceOcupacao==0){
        lista->indiceOcupacao=-1;
        exit(1);
    }

    int aux=0;
    while(aux<=lista->indiceOcupacao){
        *(lista->array+aux)=*(lista->array+(aux+1));
        aux++;
    }

    return prof;
}

Professor acessarInicioLista(ListaVetor const * const lista){
    if(verificarListaVazia(lista)){
        printf("Lista está vazia");
        exit(1);
    }

    return *(lista->array+0);
}

void inserirNaPosicao(Professor * const prof, int destino, ListaVetor *const lista){
    if(verificarListaCheia(lista)){
        printf("Fila está cheia!\n");
        return;
    }
    if(destino>lista->indiceOcupacao+1 || destino<0){
        printf("\nERRO! - Posição fora do intervalo válido\n");
        return;
    }
    lista->indiceOcupacao++;
    int aux=lista->indiceOcupacao;
    while(aux>destino){
        *(lista->array+aux)=*(lista->array+(aux-1));
        aux--;
    }
    (lista->array+destino)->matricula = prof->matricula;
    strcpy((lista->array+destino)->nome, prof->nome);
    strcpy((lista->array+destino)->escola, prof->escola);
    strcpy((lista->array+destino)->titulacao, prof->titulacao);
    strcpy((lista->array+destino)->tipoDeContrato, prof->tipoDeContrato);
}

Professor retirarPosicaoLista(int posicao, ListaVetor *const lista){
    if(verificarListaVazia(lista)){
        printf("\nLista está vazia\n");
        exit(1);
    }
    if(posicao>=lista->indiceOcupacao || posicao<0){
        printf("\nERRO - Posição fora do intervalo válido\n");
        exit(1);
    }
    Professor prof = *(lista->array+posicao);
    int aux = posicao;
    while(aux <= lista->indiceOcupacao){
        *(lista->array+aux)=*(lista->array+(aux+1));
         aux++;
    }
    lista->indiceOcupacao--;
    return prof;

}

Professor acessarPosicaoLista(int posicao, ListaVetor const * const lista){
    if(verificarListaVazia(lista)){
        printf("Lista está vazia");
        exit(1);
    }

    if(posicao>lista->indiceOcupacao || posicao<0){
        printf("\nERRO - Posição fora do intervalo válido\n");
        exit(1);
    }

    return *(lista->array+posicao);
}

void inserirOrdenadoLista(Professor *const prof, ListaVetor *const lista){
    if(verificarListaCheia(lista)){
        printf("Fila está cheia!\n");
        return;
    }
    int i=0;
    for(i = 0; i<=lista->indiceOcupacao+1 && prof->matricula > (lista->array+i)->matricula; i++);
    int posicao = i;
    inserirNaPosicao(prof,posicao,lista);

}

void liberarLista(ListaVetor *const lista){
    free(lista->array);
    lista->indiceOcupacao = 0;
    lista->tamanho = 0;
}
#endif // LISTA_H
