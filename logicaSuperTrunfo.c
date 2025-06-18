#include <stdio.h>
#include <string.h>

// Definições de tamanho para strings
#define TAM_COD 10
#define TAM_NOME 100

int main() {
    char estado1, estado2;
    char codigo_carta1[TAM_COD], codigo_carta2[TAM_COD];
    char nome_cidade1[TAM_NOME], nome_cidade2[TAM_NOME];   
    unsigned long int populacao1, populacao2;                                                                                                                    
    float area1, area2, pib1, pib2;
    int n_ptos_tur1, n_ptos_tur2;

    // Variáveis de cálculo
    float densidade1, densidade2;
    float pib_per_capita1, pib_per_capita2;

    // Coleta de dados da carta 1
    printf("Digite os dados da carta 1:\n");
    printf("Digite uma letra para o estado da carta 1 (Letras validas: A a H): ");
    scanf(" %c", &estado1);

    printf("Digite o código da carta 1, sendo uma letra e dois números (01 a 04): ");
    scanf("%s", codigo_carta1);

    printf("Digite o nome da cidade 1: ");
    scanf(" %[^\n]", nome_cidade1);

    printf("Digite a população da cidade 1: ");
    scanf("%lu", &populacao1);

    printf("Digite a área da cidade 1 (em quilômetros quadrados): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Número de pontos turísticos: ");
    scanf("%d", &n_ptos_tur1);

    // Coleta de dados da carta 2
    printf("\nDigite os dados da carta 2:\n");
    printf("Digite uma letra para o estado da carta 2 (Letras validas: A a H): ");
    scanf(" %c", &estado2);

    printf("Digite o código da carta 2, sendo uma letra e dois números (01 a 04): ");
    scanf("%s", codigo_carta2);

    printf("Digite o nome da cidade 2: ");
    scanf(" %[^\n]", nome_cidade2);

    printf("Digite a população da cidade 2: ");
    scanf("%lu", &populacao2);

    printf("Digite a área da cidade 2 (em quilômetros quadrados): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Número de pontos turísticos: ");
    scanf("%d", &n_ptos_tur2);

    // Cálculos
    densidade1 = (area1 > 0) ? populacao1 / area1 : 0;
    densidade2 = (area2 > 0) ? populacao2 / area2 : 0;

    pib_per_capita1 = (populacao1 > 0) ? (pib1 * 1e9) / populacao1 : 0;
    pib_per_capita2 = (populacao2 > 0) ? (pib2 * 1e9) / populacao2 : 0;

    int opcao1 = -1, opcao2 = -1;

    do {
        printf("\n===== MENU DE COMPARAÇÃO MULTIATRIBUTOS =====\n");
        printf("Escolha o primeiro atributo para comparação:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Número de pontos turísticos\n");
        printf("5 - Densidade demográfica (menor vence)\n");
        printf("0 - Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao1);

        if (opcao1 == 0) break;
        if (opcao1 < 1 || opcao1 > 5) {
            printf("Opção inválida. Tente novamente.\n");
            continue;
        }

        // Menu dinâmico
        printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
        for (int i = 1; i <= 5; i++) {
            if (i == opcao1) continue;
            switch(i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Número de pontos turísticos\n"); break;
                case 5: printf("5 - Densidade demográfica (menor vence)\n"); break;
            }
        }
        printf("Digite sua opção: ");
        scanf("%d", &opcao2);

        if (opcao2 == opcao1 || opcao2 < 1 || opcao2 > 5) {
            printf("Atributo inválido ou repetido. Tente novamente.\n");
            continue;
        }

        // Funçao auxiliar para obter valor de atributo
        float valor_c1_attr1 = 0, valor_c2_attr1 = 0;
        float valor_c1_attr2 = 0, valor_c2_attr2 = 0;

        float soma1 = 0, soma2 = 0;

        // Atribuiçao de valores
        float atributos1[6] = {0, populacao1, area1, pib1, n_ptos_tur1, densidade1};
        float atributos2[6] = {0, populacao2, area2, pib2, n_ptos_tur2, densidade2};

        valor_c1_attr1 = atributos1[opcao1];
        valor_c2_attr1 = atributos2[opcao1];
        valor_c1_attr2 = atributos1[opcao2];
        valor_c2_attr2 = atributos2[opcao2];

        // Calculo de soma para determinar vencedor
        soma1 = valor_c1_attr1 + valor_c1_attr2;
        soma2 = valor_c2_attr1 + valor_c2_attr2;

        printf("\n========== RESULTADOS DA COMPARAÇÃO ==========\n");
        printf("Cidade 1: %s\n", nome_cidade1);
        printf("Cidade 2: %s\n", nome_cidade2);

        // Exibe os atributos usados e seus valores
        char *nomes_atributos[] = {
            "", "População", "Área", "PIB", "Pontos Turísticos", "Densidade Demográfica"
        };

        printf("\nAtributos escolhidos: %s e %s\n", nomes_atributos[opcao1], nomes_atributos[opcao2]);
        printf("Valores da Carta 1: %.2f e %.2f\n", valor_c1_attr1, valor_c1_attr2);
        printf("Valores da Carta 2: %.2f e %.2f\n", valor_c2_attr1, valor_c2_attr2);

        // Resultado individual por atributo
        for (int i = 0; i < 2; i++) {
            int attr = (i == 0) ? opcao1 : opcao2;
            float v1 = atributos1[attr];
            float v2 = atributos2[attr];
            int vencedor = 0;
            if (attr == 5) { // densidade: menor vence
                if (v1 < v2) vencedor = 1;
                else if (v2 < v1) vencedor = 2;
            } else {
                if (v1 > v2) vencedor = 1;
                else if (v2 > v1) vencedor = 2;
            }

            printf("\nComparação do atributo \"%s\": ", nomes_atributos[attr]);
            if (vencedor == 1) printf("Carta 1 venceu");
            else if (vencedor == 2) printf("Carta 2 venceu");
            else printf("Empate");
            printf(" (%.2f vs %.2f)", v1, v2);
        }

        // Comparação total
        printf("\n\nSoma total dos atributos:\n");
        printf("Carta 1: %.2f\n", soma1);
        printf("Carta 2: %.2f\n", soma2);

        if (soma1 > soma2)
            printf("\n>>> Resultado Final: Carta 1 venceu a rodada!\n");
        else if (soma2 > soma1)
            printf("\n>>> Resultado Final: Carta 2 venceu a rodada!\n");
        else
            printf("\n>>> Resultado Final: Empate!\n");

        // Pergunta se o jogador quer continuar
        printf("\nDeseja fazer outra comparação? (1-Sim / 0-Não): ");
        scanf("%d", &opcao1);
    } while (opcao1 != 0);

    printf("Saindo do programa...\n");
    return 0;
}