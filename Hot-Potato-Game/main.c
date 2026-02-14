#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Fila.h"

int main(){
	Fila *f = queue();
	enqueue(f,1);
	enqueue(f,2);
	enqueue(f,3);
	enqueue(f,4);
	enqueue(f,5);
	enqueue(f,6);
	enqueue(f,7);
	enqueue(f,8);
	enqueue(f,9);
	enqueue(f,10);
	
	srand(time(NULL));
	
	while(f->tamanho > 1){
		int n = rand() % 50 + 1;
		int i = 0;
		printf("O numero sorteado foi %d\n",n);
		while(i != n-1){
			int x = dequeue(f);
			enqueue(f,x);
			i++;
		}
		printf("A pessoa retirada foi a do numero %d\n",dequeue(f));
	}
	printf("O vencedor foi %d\n",dequeue(f));
	return 0;
}
