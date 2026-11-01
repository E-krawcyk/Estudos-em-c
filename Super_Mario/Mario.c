#include <stdio.h>

int main(void)
{
    int tamanho;
    int resultado;
    char entrada[100];
    char extra;

    // Solicita a altura da pirâmide e lê a entrada como texto
    printf("Digite qual deve ser a altura da pirâmide (1 - 8): ");
    fgets(entrada, 100, stdin);

    // Verifica se foi digitado apenas um número válido
    resultado = sscanf(entrada, " %d %c", &tamanho, &extra);

    // Repete enquanto a entrada for inválida ou estiver fora do intervalo
    while (resultado != 1 || tamanho < 1 || tamanho > 8)
    {
        printf("Você deve digitar um número de 1 a 8. Digite novamente!\n");
        printf("Digite: ");

        fgets(entrada, 100, stdin);
        resultado = sscanf(entrada, " %d %c", &tamanho, &extra);
    }

    // Constrói a pirâmide linha por linha
    for (int linha = 1; linha <= tamanho; linha++)
    {
        // Imprime os espaços antes da primeira metade
        for (int espaco = 0; espaco < tamanho - linha; espaco++)
        {
            printf(" ");
        }

        // Imprime a primeira metade da pirâmide
        for (int hash = 0; hash < linha; hash++)
        {
            printf("#");
        }

        // Espaço entre as duas metades
        printf("  ");

        // Imprime a segunda metade da pirâmide
        for (int hash = 0; hash < linha; hash++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}