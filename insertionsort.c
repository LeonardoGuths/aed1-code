#include <stdio.h>
#include <stdlib.h>

void Insertionsort (int data[], int n) {

    int tmp,i,j;
    for (j=1; j<n; j++) {

    i = j-1;
    tmp = data[j];
    while ( (i>=0) && (tmp < data[i]) ) {

        data[i+1] = data[i];
        i--;
    }//while

    data[i+1] = tmp;
    }//for
}//Insertionsort

int main()
{
    int data[5], n, i;
    printf ("Insira 5 numeros:\n");
    for (i=0; i<5; i++)
    {
    scanf ("%d",&data[i]);
    }
    printf ("Agora insira o N: ");
    scanf ("%d",&n);

    printf ("Antes\n");
    for (i=0; i<5; i++)
    {
    printf ("%d ",data[i]);
    }

    Insertionsort (data, n);

    printf ("\nDepois\n");
    for (i=0; i<5; i++)
    {
    printf ("%d ",data[i]);
    }
return 0;
}