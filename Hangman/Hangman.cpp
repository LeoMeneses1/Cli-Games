#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	char palavra[30], secreta[30], letra; //o secreta vai ser a string que vai revelando a palavra
	int tam,i,chances,acerto,correto; 
	tam = 0;
	i = 0;
	chances = 6; 		//quantidade de chances para saber se o jogador ganhou
	acerto = 0;  		//se a quantidade de acerto for = ao tamanho ele ganhou
	
	cout << "Escolha uma palavra que vai ser a palavra a ser adivinhada\n";
	cin >> palavra;
	system("cls");
	
	while(palavra[i] != '\0'){
		tam++;
		i++;
	}
	
	for(i=0; i<tam; i++){
		secreta[i] = '_';
	}
	secreta[tam] = '\0';
	
	while(acerto < tam && chances > 0){
		correto = 0; 		//vou usar esse para saber se o jogador acertou a letra ou errou	
		cout << "\n\nEstado atual: " << secreta;
		cout << "\nEscolha uma letra: ";
		cin >> letra;
		for(i=0; i<tam; i++){
			if(letra == palavra[i]){
				if(secreta[i] == '_'){
					secreta[i] = letra;
					acerto++;
					correto = 1;
				}
			}
		}
		if(correto){
			cout << "\nVoce acertou! a Letra esta presente na palavra";
		}else{
			cout << "\nVoce errou!";
			chances--;	
			cout << "\nVoce ainda tem " << chances;
		}
	}
	if(acerto == tam){
		cout << "\nParabens, voce ganhou o jogo!!";
	}else if(acerto != tam){
		cout << "\nSuas chances esgotaram, voce perdeu, sera enforcado. A palavra era " << palavra;
	}
	
	return 0;
}
