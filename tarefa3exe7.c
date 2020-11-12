#include <stdio.h>
#include <stdlib.h>

int *removeDuplicatas (int *vet, int *n);

int main()
{
    int *v, *n, i;
    n = (int *)malloc(sizeof(int));
    printf ("Quantos numeros? ");
    scanf ("%d",&(*n));
    v = (int *)malloc(sizeof(int) * (*n));

    printf ("Digite os numeros:\n");
    for (int i=0; i<(*n); i++)
        scanf ("%d",&v[i]);

    v = removeDuplicatas(v, n);

    for (i=0; i<(*n); i++)
        printf ("%d ",v[i]);

free (n);
free (v);
return 0;
}

int *removeDuplicatas (int *vet, int *n)
{
    int *temp, p=0, nao=0, i, j;
    temp = (int *)malloc(sizeof(int));

    for (i=0; i<(*n); i++)
    {  
        nao=0;
        for (j=i+1; j<(*n); j++)
            if (vet[i] == vet[j])
                nao=1;

        if (nao==0)
        {
            temp = realloc(temp, sizeof(int) * (p+1));
            temp[p] = vet[i];
            p++;
            nao=0;
        }
    }
    free (vet);
    *n = p;
    return temp;
}