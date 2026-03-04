#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct NoCena{
	string textoNarrativo;
	NoCena *escolha1;			//texto para a prox. cena se digitar 1 ou 2
	NoCena *escolha2;			
};

void iniciarJogo(NoCena *cenaAtual){
	int escolha;
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
		"Voce acalmou o divergente. Ele confiou em voce e se entrega. [FINAL PACIFICO]",
		nullptr,
		nullptr
	};
	
	NoCena finalFrio = {
		"Voce atirou no divergente. A missao foi cumprida, mas sera que valeu a pena? [FINAL FRIO]",
		nullptr,
		nullptr
	};
	
	NoCena cenaTelhado = {
		"Voce encurralou o divergente. \n[1] Tentar acalmar o divergente. \n[2] Sacar a arma imediatamente.",
		&finalPacifico,
		&finalFrio
	};
	
	iniciarJogo(&cenaTelhado); 		//aqui inicio o jogo e levo para a funcao
	
	return 0;
}
