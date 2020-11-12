#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char linha[80], *tok;
    printf ("Digite a frase: ");
    scanf ("%[^\n]",linha);

    tok = strtok(linha, " ");
    while (tok != NULL)
    {
        printf ("%s\n",tok);
        tok = strtok(NULL, " ");
    }
}