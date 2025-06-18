#include <stdio.h>
#include <string.h>

#define TAM_COD 10
#define TAM_NOME 100

int main() {
    char estado1, estado2;
    char codigo_carta1[TAM_COD], codigo_carta2[TAM_COD];
    char nome_cidade1[TAM_NOME], nome_cidade2[TAM_NOME];   
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int n_ptos_tur1, n_ptos_tur2;

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

    int opcao;
    do {
        printf("\n===== MENU DE COMPARAÇÃO =====\n");
        printf("Escolha o atributo para comparar as cartas:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Número de pontos turísticos\n");
        printf("5 - Densidade demográfica (menor vence)\n");
        printf("0 - Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        printf("\n================== RESULTADOS ==================\n");
        printf("\nCarta 1:\n");
        printf("Cidade: %s\nPopulação: %lu\nÁrea: %.2f km²\nPIB: R$ %.2f bilhões\n", nome_cidade1, populacao1, area1, pib1);
        printf("Pontos Turísticos: %d\nDensidade: %.2f hab/km²\nPIB per Capita: %.6f\n", 
                n_ptos_tur1, densidade1, pib_per_capita1);

        printf("\nCarta 2:\n");
        printf("Cidade: %s\nPopulação: %lu\nÁrea: %.2f km²\nPIB: R$ %.2f bilhões\n", nome_cidade2, populacao2, area2, pib2);
        printf("Pontos Turísticos: %d\nDensidade: %.2f hab/km²\nPIB per Capita: %.6f\n", 
                n_ptos_tur2, densidade2, pib_per_capita2);

        printf("\n================ COMPARAÇÕES ================\n");

        switch(opcao) {
            case 1:
                printf("População: %s\n", 
                    (populacao1 > populacao2) ? "Carta 1 venceu" :
                    (populacao2 > populacao1) ? "Carta 2 venceu" : "Empate!");
                break;

            case 2:
                printf("Área: %s\n", 
                    (area1 > area2) ? "Carta 1 venceu" :
                    (area2 > area1) ? "Carta 2 venceu" : "Empate!");
                break;

            case 3:
                printf("PIB: %s\n", 
                    (pib1 > pib2) ? "Carta 1 venceu" :
                    (pib2 > pib1) ? "Carta 2 venceu" : "Empate!");
                break;

            case 4:
                printf("Número de pontos turísticos: %s\n", 
                    (n_ptos_tur1 > n_ptos_tur2) ? "Carta 1 venceu" :
                    (n_ptos_tur2 > n_ptos_tur1) ? "Carta 2 venceu" : "Empate!");
                break;

            case 5:
                printf("Densidade Populacional (menor vence): %s\n", 
                    (densidade1 < densidade2) ? "Carta 1 venceu" :
                    (densidade2 < densidade1) ? "Carta 2 venceu" : "Empate!");
                break;

            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while(opcao != 0);

    return 0;
}