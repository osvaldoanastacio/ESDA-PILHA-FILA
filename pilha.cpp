 
#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
    struct Elemento *proximo;
    struct Elemento *previous;
    char dado;
} Elemento;



typedef struct Pilha{

    struct Elemento* tail;
    struct Elemento* head;
    int size;

}Pilha;


Pilha* criaPilha();
Elemento* criaElemento(char);
void push(Pilha*,char);
int pop(Pilha*);
void mostrarPilha(Pilha*);
 
 
int main(){

Pilha* pilha = criaPilha();
Pilha* pilhaEscopos = criaPilha();


}


//=============================================

Elemento* criaElemento(char dado){
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    novo->proximo = NULL;
    novo->previous = NULL;
    novo->dado = dado;
    return novo;
}

//=============================================

Pilha* criaPilha(){
  Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
  pilha->head = NULL;
  pilha->tail = NULL;
  pilha->size = 0;

  return pilha;
}

//=============================================

void push(Pilha* pilha,char dado){
    Elemento* novo = criaElemento(dado);
  if(pilha->size == 0){
    pilha->head = novo;
    pilha->tail = novo;
  }else {
    novo->proximo = NULL;
    novo->previous = pilha->tail;
    pilha->tail->proximo = novo;
    pilha->tail = novo;
  }
  pilha->size++;

}

//=============================================


int pop(Pilha* pilha){
      Elemento* removendo = pilha->tail;
    if(removendo == pilha->head && pilha->size > 0){
      pilha->head = removendo->proximo;
      pilha->tail = NULL;
    }else if(pilha->size > 0){
      removendo->previous->proximo = NULL;
      pilha->tail = removendo->previous;
    }else{
      printf("Erro na remoção \n");
      return ' ';
    }
    char retorno = removendo->dado;
    free(removendo);
    pilha->size--;
    return retorno;

}

//=============================================



void mostrarPilha(Pilha* pilha){
    Elemento* aux = pilha->head;
    if(pilha->size == 0){
        printf("Lista Vazia");
    }

    while(aux != NULL){
        char palavra = aux->dado;
        printf("%c", palavra);
        aux = aux->proximo;
    }
}



