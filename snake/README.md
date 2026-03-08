# 🐍 Jogo da Cobrinha (Snake / Nibbles) em C

Um clone do clássico Jogo da Cobrinha desenvolvido inteiramente em **C puro**, rodando diretamente no terminal do Windows. Este projeto foi criado para aplicar conceitos de manipulação de matrizes, laços de repetição e leitura de teclado em tempo real.

![Gameplay do Jogo](animacao1.gif) ## 🕹️ Funcionalidades

- **Controle Híbrido:** Jogue usando as **Setinhas** do teclado ou as teclas **W, A, S, D**.
- **Sistema Anti-Suicídio:** A cobra não pode dar ré e bater no próprio pescoço.
- **Dificuldade Progressiva:** A cada maçã comida (`*`), a cobra cresce e o jogo fica gradativamente mais rápido.
- **Gráficos de Terminal:** Uso de caracteres UTF-8 (`█`) para criar paredes sólidas e melhorar o visual.
- **Loop de Jogo:** Tela de *Game Over* com opções de jogar novamente ou sair, sem fechar o terminal derrepente.

## 🛠️ Tecnologias Utilizadas

- **Linguagem:** C
- **Bibliotecas:** `<stdio.h>`, `<stdlib.h>`, `<windows.h>` (Manipulação do cursor e cores), `<conio.h>` (Leitura assíncrona do teclado), `<time.h>` e `<stdbool.h>`.

## ⚙️ Como Compilar e Rodar

1. Abra o terminal na pasta do projeto e compile o código avisando o compilador para usar o padrão C99:
   ```bash
   gcc Nibbles.c -o jogo.exe -std=c99
   ./jogo.exe

**Pré-requisitos:** Você precisa estar no Windows e ter um compilador C instalado (como o GCC / MinGW).