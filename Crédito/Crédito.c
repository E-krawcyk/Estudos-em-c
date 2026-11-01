#include <stdio.h>

int main(void)
{
    char entrada[100];
    int i = 0;
    int soma = 0;

    // Solicita o número do cartão
    printf("Digite um número de cartão válido:\n");
    fgets(entrada, 100, stdin);

    // Descobre quantos dígitos foram informados
    while (entrada[i] != '\0' && entrada[i] != '\n')
    {
        i++;
    }

    // Soma os dígitos em posições alternadas, dobrando seus valores
    int posicao = i - 2;

    while (posicao >= 0)
    {
        int digito = entrada[posicao] - '0';

        digito = digito * 2;
        digito = (digito / 10) + (digito % 10);

        soma = soma + digito;
        posicao -= 2;
    }

    // Soma os demais dígitos do cartão
    posicao = i - 1;

    while (posicao >= 0)
    {
        int digito = entrada[posicao] - '0';

        soma = soma + digito;
        posicao -= 2;
    }

    // Verifica se o número atende ao cálculo de validação
    if (soma % 10 == 0)
    {
        // American Express
        if (i == 15 && entrada[0] == '3' &&
            (entrada[1] == '4' || entrada[1] == '7'))
        {
            printf("AMEX\n");
        }

        // Mastercard
        else if (i == 16 && entrada[0] == '5' &&
                 (entrada[1] >= '1' && entrada[1] <= '5'))
        {
            printf("MASTERCARD\n");
        }

        // Visa
        else if ((i == 13 || i == 16) && entrada[0] == '4')
        {
            printf("VISA\n");
        }

        else
        {
            printf("Cartão inválido!\n");
        }
    }
    else
    {
        printf("Cartão inválido!\n");
    }

    return 0;
}