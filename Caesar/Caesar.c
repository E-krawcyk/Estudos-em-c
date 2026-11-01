#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Verifica se o usuário informou a chave corretamente
    if (argc != 2)
    {
        printf("Uso: ./caesar chave\n");
        return 1;
    }

    // Verifica se todos os caracteres da chave são números
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Uso: ./caesar chave\n");
            return 1;
        }
    }

    // Converte a chave recebida de texto para número inteiro
    int chave = atoi(argv[1]);

    char texto[1000];

    // Solicita o texto que será criptografado
    printf("Texto original: ");
    fgets(texto, 1000, stdin);

    // Percorre cada caractere do texto
    for (int i = 0; texto[i] != '\0'; i++)
    {
        // Criptografa letras maiúsculas
        if (isupper(texto[i]))
        {
            texto[i] = (texto[i] - 'A' + chave) % 26 + 'A';
        }

        // Criptografa letras minúsculas
        else if (islower(texto[i]))
        {
            texto[i] = (texto[i] - 'a' + chave) % 26 + 'a';
        }
    }

    // Exibe o texto criptografado
    printf("Texto criptografado: %s", texto);

    return 0;
}