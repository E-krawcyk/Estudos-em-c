#include <stdio.h>

int main(void)
{
    int inicio;
    int final;
    int anos = 0;

    char entrada[100];
    int resultado;
    char extra;

    // Solicita a população inicial e valida a entrada
    do
    {
        printf("Insira a população inicial: ");
        fgets(entrada, 100, stdin);

        resultado = sscanf(entrada, " %d %c", &inicio, &extra);

    } while (resultado != 1 || inicio < 9);

    // Solicita a população final e garante que ela seja maior ou igual à inicial
    do
    {
        printf("Insira a população final: ");
        fgets(entrada, 100, stdin);

        resultado = sscanf(entrada, " %d %c", &final, &extra);

    } while (resultado != 1 || final < inicio);

    // Calcula quantos anos são necessários para atingir a população final
    while (final > inicio)
    {
        inicio = inicio + (inicio / 3) - (inicio / 4);
        anos++;
    }

    // Exibe o total de anos necessários
    printf("Anos passados: %i\n", anos);

    return 0;
}