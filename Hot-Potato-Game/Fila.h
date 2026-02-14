#ifndef FILA_H
#define FILA_H

typedef struct No{
	int identificacao;
	struct No *prox;
}No;

typedef struct{
	No *inicio;
	No *fim;
	int tamanho;
}Fila;

Fila* queue();

void enqueue(Fila *f, int item);

int dequeue(Fila *f);

#endif
