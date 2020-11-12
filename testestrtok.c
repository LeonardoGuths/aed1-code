#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **stringona;
    char string[50];
    int t;

    //stringona = (char *)malloc(sizeof(char));
    

    printf ("dale o nome: ");
    scanf ("%[^\n]",string);
    getchar();
    
    t = strlen(string);

    stringona = (char *) malloc(sizeof(char) * (t+1));

    strcat (*stringona, string);

    printf ("\nstringona: %s \n",*stringona);

    printf ("dale o nome: ");
    scanf ("%[^\n]",string);

    stringona = (char *) realloc(stringona, sizeof(stringona) + sizeof(char) * ((strlen(string))+1));

    printf ("\nstringona: %s \n",*stringona);

free (stringona);
return 0;
}
