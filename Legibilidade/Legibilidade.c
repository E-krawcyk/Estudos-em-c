#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    char caractere[1000];
    int palavras = 1;

    // Solicita o texto que será analisado
    printf("Digite seu texto: ");
    fgets(caractere, 1000, stdin);

    int letras = 0;
    int frases = 0;

    // Conta letras, palavras e frases
    for (int i = 0; caractere[i] != '\0'; i++)
    {
        if (isalpha(caractere[i]))
        {
            letras++;
        }

        if (caractere[i] == ' ')
        {
            palavras++;
        }

        if (caractere[i] == '.' || caractere[i] == '!' || caractere[i] == '?')
        {
            frases++;
        }
    }

    // Calcula a média de letras e frases a cada 100 palavras
    float L = ((float)letras / palavras) * 100;
    float S = ((float)frases / palavras) * 100;

    // Aplica o índice de legibilidade Coleman-Liau
    float index = 0.0588 * L - 0.296 * S - 15.8;

    int nivel = round(index);

    // Exibe o nível de leitura estimado
    if (nivel < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (nivel >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", nivel);
    }
}