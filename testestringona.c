#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **stringona;
    char string[50];
    int t;

    printf ("dale o nome: ");
    scanf ("%[^\n]",string);
    getchar();

    t = strlen(string);

    stringona = (char **)malloc(sizeof(char) * (t+1));

    strcpy (*stringona, string);

    printf ("dale o nome: ");
    scanf ("%[^\n]",string);
    getchar();

    t = strlen(string);

    stringona = (char *) realloc(stringona, sizeof(stringona) + sizeof(char) * (t+1));

    strcat(stringona, " ");
    strcat(stringona, string);


    printf ("dale o nome: ");
    scanf ("%[^\n]",string);
    getchar();

    t = strlen(string);

    stringona = (char *) realloc(stringona, sizeof(stringona) + sizeof(char) * (t+1));

    strcat(stringona, " ");
    strcat(stringona, string);

    printf ("\nstringona: %s ",*stringona);

free (stringona);
return 0;
}