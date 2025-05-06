#include <stdio.h>
#include <string.h>

struct Cidade {
    char estado[10]; 
    char codigo[10];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib; // PIB em bilhões
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
};

void limparBuffer() {
    while (getchar() != '\n');
}

void lerCidade(struct Cidade *cidade, int numero) {
    printf("\nDigite os dados da Carta %d:\n", numero);

    printf("Estado: ");  
    scanf("%2s", cidade->estado);

    printf("Código: ");
    scanf("%s", cidade->codigo);

    limparBuffer();
    printf("Nome da Cidade: ");
    fgets(cidade->nome, sizeof(cidade->nome), stdin);
    cidade->nome[strcspn(cidade->nome, "\n")] = 0;

    printf("População: ");
    scanf("%lu", &cidade->populacao);

    printf("Área (km²): ");
    scanf("%f", &cidade->area);

    printf("PIB (bilhões de reais): ");
    scanf("%f", &cidade->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &cidade->pontosTuristicos);

    cidade->densidadePopulacional = (float)cidade->populacao / cidade->area;
    cidade->pibPerCapita = (cidade->pib * 1e9f) / cidade->populacao;

    cidade->superPoder =
        (float)cidade->populacao +
        cidade->area +
        (cidade->pib * 1e9f) +
        (float)cidade->pontosTuristicos +
        cidade->pibPerCapita +
        (1.0f / cidade->densidadePopulacional);
}

void imprimirCidade(struct Cidade cidade, int numero) {
    printf("\n=== Carta %d ===\n", numero);
    printf("Estado: %s\n", cidade.estado);
    printf("Código: %s\n", cidade.codigo);
    printf("Nome da Cidade: %s\n", cidade.nome);
    printf("População: %lu\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: %.2f bilhões de reais\n", cidade.pib);
    printf("Número de Pontos Turísticos: %d\n", cidade.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", cidade.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", cidade.pibPerCapita);
    printf("Super Poder: %.2f\n", cidade.superPoder);
}

void compararPorPopulacao(struct Cidade c1, struct Cidade c2) {
    printf("\n=== Comparação de Cartas (Atributo: População) ===\n");

    printf("Carta 1 - %s (%s): %lu\n", c1.nome, c1.estado, c1.populacao);
    printf("Carta 2 - %s (%s): %lu\n", c2.nome, c2.estado, c2.populacao);

    if (c1.populacao > c2.populacao)
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome);
    else if (c2.populacao > c1.populacao)
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome);
    else
        printf("Resultado: Empate!\n");
}

int main() {
    struct Cidade cidade1, cidade2;

    lerCidade(&cidade1, 1);
    lerCidade(&cidade2, 2);

    imprimirCidade(cidade1, 1);
    imprimirCidade(cidade2, 2);

    compararPorPopulacao(cidade1, cidade2);

    return 0;
}