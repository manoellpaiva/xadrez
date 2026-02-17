#include <stdio.h>

/* =========================================================
   FUNÇÃO RECURSIVA - TORRE
   Move N casas para a Direita, imprimindo a cada casa.
   ========================================================= */
void moverTorreRec(int casasRestantes) {
    if (casasRestantes <= 0) {
        return; // caso base: parou de mover
    }

    printf("Direita\n");
    moverTorreRec(casasRestantes - 1); // chamada recursiva
}

/* =========================================================
   FUNÇÃO RECURSIVA - RAINHA
   Move N casas para a Esquerda, imprimindo a cada casa.
   ========================================================= */
void moverRainhaRec(int casasRestantes) {
    if (casasRestantes <= 0) {
        return; // caso base
    }

    printf("Esquerda\n");
    moverRainhaRec(casasRestantes - 1); // recursão
}

/* =========================================================
   FUNÇÃO RECURSIVA - BISPO (com loops aninhados)
   Requisito: recursividade + loops aninhados
   - Loop externo: movimento vertical (Cima)
   - Loop interno: movimento horizontal (Direita)
   A cada "casa" diagonal, imprimimos:
   Cima
   Direita
   (duas linhas por casa, mantendo o padrão exigido)
   ========================================================= */
void moverBispoRecComLoops(int casasRestantes) {
    if (casasRestantes <= 0) {
        return; // caso base
    }

    /* Para representar 1 casa na diagonal (Cima + Direita),
       usamos loops aninhados:
       - externo controla o "vertical" (1 passo)
       - interno controla o "horizontal" (1 passo) */
    for (int passoVertical = 1; passoVertical <= 1; passoVertical++) {
        printf("Cima\n");

        for (int passoHorizontal = 1; passoHorizontal <= 1; passoHorizontal++) {
            printf("Direita\n");
        }
    }

    moverBispoRecComLoops(casasRestantes - 1); // próxima casa diagonal
}

int main() {

    /* ==========================
       VALORES FIXOS NO CÓDIGO
       ========================== */
    int casasTorre  = 5; // Torre: 5 para a direita
    int casasBispo  = 5; // Bispo: 5 na diagonal (Cima + Direita)
    int casasRainha = 8; // Rainha: 8 para a esquerda

    printf("Movimento da Torre:\n");
    moverTorreRec(casasTorre);

    printf("\nMovimento do Bispo:\n");
    moverBispoRecComLoops(casasBispo);

    printf("\nMovimento da Rainha:\n");
    moverRainhaRec(casasRainha);

    /* =========================================================
       CAVALO - LOOPS ANINHADOS MAIS COMPLEXOS
       Movimento em L: 2 para Cima e 1 para Direita

       Requisitos:
       - loops aninhados
       - múltiplas variáveis e/ou condições
       - pode usar continue e break
       - imprimir por casa: "Cima", "Cima", "Direita"
       ========================================================= */

    printf("\nMovimento do Cavalo:\n");

    int alvoVertical = 2;     // duas casas para cima
    int alvoHorizontal = 1;   // uma casa para direita

    /* Loop externo controla "etapas" do L:
       etapa 0 -> faz o movimento vertical (2x Cima)
       etapa 1 -> faz o movimento horizontal (1x Direita) */
    for (int etapa = 0; etapa < 2; etapa++) {

        /* Loop interno com múltiplas variáveis/condições:
           i -> contador de passos
           limite -> muda conforme a etapa */
        int i = 0;
        int limite = (etapa == 0) ? alvoVertical : alvoHorizontal;

        while (i <= limite) {

            /* Exemplo de controle fino:
               i == 0 não imprime nada (ajuda a mostrar uso de continue),
               só incrementa e segue. */
            if (i == 0) {
                i++;
                continue;
            }

            if (etapa == 0) {
                printf("Cima\n");
            } else {
                printf("Direita\n");
            }

            /* Se já fez o número necessário de passos, pode parar cedo */
            if (i == limite) {
                break; // encerra o loop interno nessa etapa
            }

            i++;
        }
    }

    return 0;
}
