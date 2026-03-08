# 🎮 CLI Games

Bem-vindo ao meu repositório de jogos desenvolvidos em **C** e **C++**. 
Este projeto reúne implementações clássicas de jogos rodando diretamente no terminal (Command Line Interface), com foco no estudo aprofundado de **Estruturas de Dados**, **Algoritmos** e **Gerenciamento de Memória**.

## 🚀 Projetos Incluídos

| Jogo | Linguagem | Conceitos Chave Aplicados |
| :--- | :---: | :--- |
| **[Batata Quente](./Hot-Potato-Game)** | C | **TAD Fila**, Ponteiros, Alocação Dinâmica (`malloc/free`), Structs. |
| **[Jogo da Forca](./Hangman)** | C++ | Manipulação de Strings, Leitura de Arquivos, Lógica Condicional. |
| **[Detroit CLI](./Detroit-CLI)** | C++ | **Árvores de Decisão**, Ponteiros, Lógica Condicional, Gerenciamento de Estado (Flags). |
| **[Jogo da Cobrinha (Snake)](./snake)** | C | **Matrizes 2D**, Game Loop em Tempo Real, Leitura Assíncrona de I/O, Sistema de Coordenadas. |

---

## 💻 Destaques Técnicos

### 1. Batata Quente
Uma simulação do clássico problema matemático de Flavius Josephus.
- **Implementação:** Utiliza um **TAD (Tipo Abstrato de Dado)** de Fila criado do zero.
- **Lógica:** A fila simula um círculo onde a rotação é feita através de operações de `enqueue` (enfileirar) e `dequeue` (desenfileirar), sem necessidade de listas encadeadas circulares complexas.
- **Memória:** Foco total na prevenção de *memory leaks* (vazamento de memória) ao liberar nós removidos.

### 2. Jogo da Forca
O clássico jogo de adivinhação de palavras.
- **Funcionalidades:** Validação de entrada e tratamento de caracteres.

### 3. Detroit CLI
Um mini-motor de ficção interativa em texto inspirado na narrativa de *Detroit: Become Human*.
- **Implementação:** Utiliza uma estrutura baseada em **Árvores de Decisão** / Grafos, onde cada cena é um `struct` (Nó) conectado aos próximos caminhos através de ponteiros.
- **Lógica:** O roteiro avança navegando pelos endereços de memória. O motor possui sistema de variável de estado ("Flag") que lembra uma ação passada do jogador para alterar ramificações futuras.

### 4. Jogo da Cobrinha (Nibbles)
Um clone do clássico Snake rodando de forma fluida e em tempo real no terminal.

- **Implementação:** Matrizes bidimensionais para o mapeamento do cenário e controle de colisão (paredes e próprio corpo).
- **Lógica (Game Loop):** Motor de jogo contínuo com controle de framerate e dificuldade progressiva. Utiliza leitura assíncrona do teclado (`_kbhit()`) para não bloquear a execução, permitindo movimentação constante.
- **Visual:** Renderização otimizada sobrescrevendo o frame atual na coordenada `(0,0)` para evitar *scroll* da tela, além do uso de codificação UTF-8 para exibir blocos sólidos (`█`) e cores no terminal do Windows.

---

## ⚙️ Como Compilar e Rodar

Para rodar os jogos, você precisará de um compilador instalado (GCC ou G++).

### Para jogos em C (ex: Batata Quente):
Navegue até a pasta do jogo e compile incluindo a implementação do TAD:
```bash
cd batata-quente
gcc main.c Fila.c -o jogo
./jogo  # (No Windows: .\jogo.exe)
