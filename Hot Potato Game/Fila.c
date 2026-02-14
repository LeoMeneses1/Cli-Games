#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

Fila* queue(){
	Fila *f = malloc(sizeof(Fila));
	if(f == NULL){
		return NULL;
	}
	f->tamanho = 0;
	f->inicio = NULL;
	f->fim = NULL;
	return f;
}

void enqueue(Fila *f, int item){
	if(f == NULL){
		return;
	}
	No *novo = malloc(sizeof(No));
	if(novo == NULL){
		return;
	}
	novo->identificacao = item;
	novo->prox = NULL;
	if(f->inicio == NULL){
		f->inicio = novo;
		f->fim = novo;
	}else{
		f->fim->prox = (struct No*)novo;
		f->fim = novo;
	}
	f->tamanho++;
}

int dequeue(Fila *f){
	if(f == NULL || f->inicio == NULL || f->tamanho == 0){
		return 0;
	}
	No *aux = f->inicio;
	int valor = aux->identificacao;
	f->inicio = (No*)f->inicio->prox;
	if(f->inicio == NULL){
		f->fim = NULL;
	}
	free(aux);
	f->tamanho--;
	return valor;	
}
