#include <stdio.h>
#include <ctype.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Calcula a pontuação de uma palavra
int compute_score(char word[]);

int main(void)
{
    char jogador1[100];
    char jogador2[100];

    // Solicita as palavras dos dois jogadores
    printf("Jogador 1: ");
    fgets(jogador1, 100, stdin);

    printf("Jogador 2: ");
    fgets(jogador2, 100, stdin);

    // Calcula a pontuação de cada palavra
    int pontos1 = compute_score(jogador1);
    int pontos2 = compute_score(jogador2);

    // Compara as pontuações e informa o resultado
    if (pontos1 > pontos2)
    {
        printf("Jogador 1 venceu!\n");
    }
    else if (pontos1 == pontos2)
    {
        printf("Empate!\n");
    }
    else
    {
        printf("Jogador 2 venceu!\n");
    }

    return 0;
}

int compute_score(char word[])
{
    int soma = 0;

    // Percorre cada caractere da palavra
    for (int i = 0; word[i] != '\0'; i++)
    {
        // Soma a pontuação das letras minúsculas
        if (islower(word[i]))
        {
            soma = soma + POINTS[word[i] - 'a'];
        }

        // Soma a pontuação das letras maiúsculas
        else if (isupper(word[i]))
        {
            soma = soma + POINTS[word[i] - 'A'];
        }
    }

    return soma;
}