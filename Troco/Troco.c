#include <stdio.h>
#include <math.h>

int main(void)
{
    float reais;
    char entrada[100];
    int resultado;

    // Solicita o valor devido
    printf("Digite o valor devido: ");
    fgets(entrada, 100, stdin);
    resultado = sscanf(entrada, "%f", &reais);

    // Valida a entrada para aceitar apenas valores numéricos não negativos
    while (resultado != 1 || reais < 0)
    {
        printf("Digite um valor válido novamente: ");
        fgets(entrada, 100, stdin);
        resultado = sscanf(entrada, "%f", &reais);
    }

    // Converte o valor para centavos
    int centavos = round(reais * 100);
    int moedas = 0;

    // Calcula a quantidade mínima de moedas necessárias
    while (centavos >= 25)
    {
        centavos = centavos - 25;
        moedas++;
    }

    while (centavos >= 10)
    {
        centavos = centavos - 10;
        moedas++;
    }

    while (centavos >= 5)
    {
        centavos = centavos - 5;
        moedas++;
    }

    while (centavos >= 1)
    {
        centavos = centavos - 1;
        moedas++;
    }

    // Exibe a quantidade total de moedas
    printf("%i\n", moedas);

    return 0;
}