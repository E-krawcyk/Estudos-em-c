#include <stdio.h>
#include <string.h>
#include <ctype.h>

char substituir(char letra, char chave[]);

int main(int argc, char *argv[])
{
    // Verifica se o usuário informou uma chave
    if (argc != 2)
    {
        printf("Uso: ./substitution chave\n");
        return 1;
    }

    // A chave deve conter exatamente 26 caracteres
    if (strlen(argv[1]) != 26)
    {
        printf("A chave deve conter 26 caracteres.\n");
        return 1;
    }

    // Verifica se a chave contém apenas letras
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("A chave deve conter apenas letras.\n");
            return 1;
        }
    }

    // Verifica se existem letras repetidas na chave
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (tolower(argv[1][i]) == tolower(argv[1][j]))
            {
                printf("A chave não pode conter letras repetidas.\n");
                return 1;
            }
        }
    }

    char texto[1000];

    // Solicita o texto que será cifrado
    printf("Texto simples: ");
    fgets(texto, 1000, stdin);

    // Substitui cada letra de acordo com a chave informada
    for (int i = 0; texto[i] != '\0'; i++)
    {
        texto[i] = substituir(texto[i], argv[1]);
    }

    printf("Texto cifrado: %s", texto);

    return 0;
}

// Retorna a letra correspondente na chave de substituição
char substituir(char letra, char chave[])
{
    if (isupper(letra))
    {
        int posicao = letra - 'A';
        return toupper(chave[posicao]);
    }

    if (islower(letra))
    {
        int posicao = letra - 'a';
        return tolower(chave[posicao]);
    }

    return letra;
}