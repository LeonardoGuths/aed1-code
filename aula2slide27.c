#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *realloque(void *pont, size_t newSize)
{
    void *newEnd, *x;

    newEnd = (void *)malloc(newSize);

    if (newEnd != NULL)
    {
        memcpy(newEnd, pont, _msize(pont));
        free(pont);
        return newEnd;
    }
    else
        printf("Acabou a memoria, nao da pra botar mais!");
    
}

int main(){
    int *n, opc=1, quantos=1;
    n = (int *)malloc(sizeof(int));

    printf("Bom dia cidadao insira um numero: ");
    scanf("%d",&(*n));
    printf("Quer botar mais um? (1.Sim 2.Nao): ");
    scanf("%d",&opc);
    while (opc!=2)
    {
        quantos++;
        n = (int *)realloque(n, sizeof(int) * quantos);
        printf("Insira: ");
        scanf("%d",&n[quantos-1]);

        printf("Quer botar mais um? (1.Sim 2.Nao): ");
        scanf("%d",&opc);
    }

    for (int i=0; i<quantos; i++)
    {
        printf ("%d ",n[i]);
    }
free(n);
return 0;
}
