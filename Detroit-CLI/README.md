# 🤖 Detroit CLI: Ficção Interativa em C++

Um jogo de aventura em texto baseado em escolhas, inspirado no universo de *Detroit: Become Human*. 

⚠️ **Aviso Importante:** Este projeto não tem como objetivo ser um clone ou uma recriação idêntica do jogo original. É um exercício acadêmico criado para aplicar na prática conceitos de Estrutura de Dados em C++. Todo o foco do desenvolvimento está na lógica, e não em replicar a história comercial. Como um fã do jogo, decidi usar ele como base.

## 📂 Estrutura do Projeto

Nesta pasta, você vai encontrar duas versões do código, 

* **`versao_simples.cpp`:** A primeira implementação, onde eu estava testando e sendo uma historia mais linear.
* **`main.cpp`:** O código refatorado. Isola o motor do jogo numa função e implementa variáveis de estados (*Flag* e *ID* de cena) para criar um final dinamico com base na escolha passada do jogador.

## 🕹️ Como compilar e jogar

Usa um compilador C++ (como o G++) para compilar a versão que desejas testar:

```bash
# Para compilar a versão dinâmica:
g++ main.cpp -o detroit

# Para executar (Linux/Mac):
./detroit

# Para executar (Windows):
.\detroit.exe