#include <stdio.h>
#include <conio.h>		//vai me ajudar a fazer a cobrinha andar independente do buffer de entrada
#include <stdlib.h>
#include <time.h>		//para mexer com o tempo
#include <stdbool.h>
#include <windows.h>

#define largura 70
#define altura 25			//tamanho do nosso campinho
#define tamanhoMax 120		//tamanho maximo da cobra

typedef struct{
	int y[tamanhoMax];		//estou preechendo todos os lugares que nossa cobra
	int x[tamanhoMax];		//pode estar 
	int comprimento;		//o comprimento que nossa cobra tem a cada vez que ela come
	int direcaox;			
	int direcaoy;						
}Cobra;

typedef struct{
	int x;
	int y;
}Comida;					//a comida vai ter uma posicao x e y

Cobra cobra;
Comida comida;
bool gameOver = false;  	//enquanto o game over for falso, o jogo nao termina
char telaBuffer[altura][largura];	//array da tela
int pontuacao = 0;
int velocidade = 75;		//vou ajustando a velocidade do jogo

void mudarCor(int cor){		//para colocar cor no terminal do windows
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, cor);
}

void gerarComida(){
	comida.x = rand() % (largura-2) + 1;
	comida.y = rand() % (altura-2) + 1;
}

void inicializar(){
	srand(time(NULL));
	
	pontuacao = 0;			//como vou reiniciar o jogo, preciso voltar aos numeros do comeco da partida
    velocidade = 75;
    gameOver = false;
	
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //esconde o cursor do terminal, pra ficar bonito
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
    SetConsoleOutputCP(CP_UTF8); 		//deixar a parede mais bonita
    
    cobra.comprimento = 1;
    cobra.x[0] = largura/2;
    cobra.y[0] = altura/2;
    cobra.direcaox = 1;
    cobra.direcaoy = 0; 		//ela vai comecar indo pro lado;
    
    gerarComida();
    
    for(int i=0; i<altura; i++){		//estou preenchendo a tela
    	for(int j=0; j<largura; j++){
    		if(i == 0 || i == altura-1 || j == 0 || j == largura-1){
    			telaBuffer[i][j] = '#';			//limite da tela
			}else{
				telaBuffer[i][j] = ' ';
			}
		}
	}
}


void moverCursorInicio(){		//so ove o cursor do terminal para o topo
	COORD pos = {0, 0};			//para redesenhar a tela em cima da antiga e nao ficar voltando
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
	
}

void desenhar(){
	moverCursorInicio();
	for(int i=0; i<altura; i++){	
    	for(int j=0; j<largura; j++){
    		
    		bool imprimiuAlgo = false;					//flag para desenhar a cobra
    		if(j == cobra.x[0] && i == cobra.y[0]){		//se for cabeca da cobra vou colocar o O
    			mudarCor(10); 	//10 = verde;
    			printf("@");
    			imprimiuAlgo = true;
    			
			}else if(j == comida.x && i == comida.y){
				mudarCor(12);
				printf("*");
				imprimiuAlgo = true;
			}else{
				for(int k=1; k<cobra.comprimento; k++){		//se nao eh cabeca eh corpo
					if(j == cobra.x[k] && i == cobra.y[k]){
						mudarCor(2);
						printf("o");
						imprimiuAlgo = true;
						break;
					}
				}
			}
			if(!imprimiuAlgo){								//se nao for cobra, eh cenario
				if(telaBuffer[i][j] == '#'){
					mudarCor(8);
					printf("¦");
				}else{
					mudarCor(15);
					printf("%c",telaBuffer[i][j]);
				}
			}
		}
		printf("\n");
	}
	mudarCor(15);
	printf("\nSua pontuacao eh: %d",pontuacao);
}

void entrada(){
	if(_kbhit()){					//se a tecla foi pressionada
		int tecla = _getch();		//vou guardar a tecla pressionada em uma variavel
		if(tecla == 224 || tecla == 0){
            tecla = _getch(); // lemos de novo para pegar a direção real!
            if(tecla == 75) { // Seta para ESQUERDA
                if(cobra.direcaox != 1){ 
					cobra.direcaox = -1; 
					cobra.direcaoy = 0; 
				}
            }else if(tecla == 77){ // Seta para DIREITA
                if(cobra.direcaox != -1){ 
					cobra.direcaox = 1; 
					cobra.direcaoy = 0; 
				}
            }else if(tecla == 72){ // Seta para CIMA
                if(cobra.direcaoy != 1){ 
					cobra.direcaox = 0;
					cobra.direcaoy = -1;
				}
            }else if(tecla == 80){ // Seta para BAIXO
                if(cobra.direcaoy != -1){ 
					cobra.direcaox = 0; 
					cobra.direcaoy = 1;
				}
            }
        }else{
        	if(tecla == 'a' || tecla == 'A'){
        		if(cobra.direcaox != 1){
        			cobra.direcaox = -1;
        			cobra.direcaoy = 0;
				}
			}else if(tecla == 'd' || tecla == 'D'){
				if(cobra.direcaox != -1){
					cobra.direcaox = 1;
					cobra.direcaoy = 0;
				}
			}else if(tecla == 'w' || tecla == 'W'){
				if(cobra.direcaoy != 1){
					cobra.direcaox = 0;
					cobra.direcaoy = -1;
				}
			}else if(tecla == 's' || tecla == 'S'){
				if(cobra.direcaoy != -1){
					cobra.direcaox = 0;
					cobra.direcaoy = 1;
				}
			}else if(tecla == 'x' || tecla == 'X' || tecla == 'q' || tecla == 'Q'){
				gameOver = true;
			}
		}
	}
}

void movimento(){
	int novoX = cobra.x[0] + cobra.direcaox;	//vai ser a posicao da cabeca da cobra +
	int novoY = cobra.y[0] + cobra.direcaoy;	//a posicao que a direcao ta indo
	if(novoX <= 0 || novoX >= largura-1 || novoY <= 0 || novoY >= altura-1){
		gameOver = true;
	}
	
	for(int k=1; k < cobra.comprimento; k++){
		if(cobra.x[k] == novoX && cobra.y[k] == novoY){
			gameOver = true;
		}	
	}
	
	if(novoX == comida.x && novoY == comida.y){	//estou fazendo colisao com a fruta
		cobra.comprimento++;
		pontuacao += 10;							
		telaBuffer[comida.y][comida.x] = ' ';	//no lugar da fruta fica o caractere vazio
		gerarComida();
		if(velocidade > 10) velocidade -= 5; 	//aumento a velocidade para dificultar o jogo
	}
	
	for(int i=cobra.comprimento-1; i > 0; i--){	//isso faz com que a cobra va aumentando e seguindo o corpo
		cobra.x[i] = cobra.x[i-1];				//fazemos isso do final a cabeca
		cobra.y[i] = cobra.y[i-1];
	}
	cobra.x[0] = novoX;
	cobra.y[0] = novoY;
}

int main(){
	while(true){
		inicializar();
		while(!gameOver){
			desenhar();
			entrada();
			movimento();
			Sleep(velocidade);		//vai ser a velocidade do jogo que vai aumentando a cada vez que a cobra come uma comida
		}
		// --- Tela de Game Over --- [feita com ajuda de ia]
        system("cls"); //Limpa a tela inteira do terminal
        
        mudarCor(12); 
        printf("\n\n");
        printf("\t====================================\n");
        printf("\t             GAME OVER              \n");
        printf("\t====================================\n\n");
        
        mudarCor(15); 
        printf("\t      Sua pontuacao final: %d\n\n", pontuacao);
        
        mudarCor(10); 
        printf("\t [R] Jogar Novamente\n");
        printf("\t [Q] Sair do Jogo\n\n");
        char escolha;
        while(true){
            if(_kbhit()){
                escolha = _getch();
                if(escolha == 'r' || escolha == 'R' || escolha == 'q' || escolha == 'Q'){
                    break; // Sai do laço de espera
                }
            }
        }
        if(escolha == 'q' || escolha == 'Q'){
            break; 
        }
    }
    system("cls"); 
    mudarCor(15);
    printf("Obrigado por jogar! Criado por Leonardo.\n");
    
    return 0;
}


