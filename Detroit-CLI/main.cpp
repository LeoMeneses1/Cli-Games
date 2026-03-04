#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct NoCena{
	int idCena;  		//novidade para sabermos em qual cena estamos
	string textoNarrativo;
	NoCena *escolha1;			//texto para a prox. cena se digitar 1 ou 2
	NoCena *escolha2;			
};

void iniciarJogo(NoCena *cenaAtual){
	int escolha;
	bool armado = false;		//inicialmente vamos dizer que nao pegou a arma
	cout << "=== INICIANDO O JOGO ===" << endl;
	while(cenaAtual != nullptr){
		cout << "\n---------------------" << endl;
		cout << cenaAtual->textoNarrativo << endl;
		if(cenaAtual->escolha1 == nullptr && cenaAtual->escolha2 == nullptr){
			cout << "\nFIM DE JOGO. ESPERO QUE TENHA GOSTADO! EM BREVE, TEREMOS A CONTINUACAO..." << endl;
			break;
		}
		cout << "\nEscolha a sua acao(1 ou 2): ";
		cin >> escolha;
		
		//aqui vamos mudar um pouco o final, vamos avaliar se o jogador pegou ou nao a arma
		//e a interferencia disso no jogo
		
		//se estamos na cena da sala (1) e o jogador escolheu a arma, mudamos a flag
		if(cenaAtual->idCena == 1){
			if(escolha == 1){
				armado = true;
				cout << "Voce decidiu pegar a arma" << endl;
			}else{
				cout << "Voce deixou a arma para tras" << endl;
			}
		}
		
		if(cenaAtual->idCena == 2 && escolha == 2){
			if(armado == false){
				cout << "Voce decidiu atirar, mas voce nao tinha arma... O divergente percebe e consegue fugir\n";
				cout << "[FINAL SECRETO: O divergente foge]\n";
				cout << "\nFIM DE JOGO. ESPERO QUE TENHA GOSTADO! EM BREVE, TEREMOS A CONTINUACAO..." << endl;
				break;
			}
		}
		if(escolha == 1){
			cenaAtual = cenaAtual->escolha1;
		}else if(escolha == 2){
			cenaAtual = cenaAtual->escolha2;
		}else{
			cout << "\nERRO. ACAO INVALIDA. TENTE NOVAMENTE" << endl;
		}
	}
}

int main(){
	NoCena finalPacifico = { 		//aqui eu vou criar as cenas do final pro comeco
		99,
		"Voce acalmou o divergente. Ele confiou em voce e se entrega. [FINAL PACIFICO]",
		nullptr,
		nullptr
	};
	
	NoCena finalFrio = {
		99,
		"Voce atirou no divergente. A missao foi cumprida, mas sera que valeu a pena? [FINAL FRIO]",
		nullptr,
		nullptr
	};
	
	NoCena cenaTelhado = {
		2,
		"Voce encurralou o divergente. \n[1] Tentar acalmar o divergente. \n[2] Sacar a arma imediatamente.",
		&finalPacifico,
		&finalFrio
	};
	
	//uma nova cena
	NoCena cenaSala = {
		1,
		"Voce encontrou uma arma no chao. \n[1] Pegar a arma e continuar. (Eh contra lei usar armas de fogo). \n[2] Ignorar arma para nao perder tempo.",
		&cenaTelhado,
		&cenaTelhado
	};
	
	iniciarJogo(&cenaSala); 		//aqui inicio o jogo e levo para a funcao
	return 0;
}
