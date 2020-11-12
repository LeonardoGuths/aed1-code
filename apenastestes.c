#include <stdio.h>
#include <stdlib.h>
/*
int main()
{
    int mat[2][2] = {{1,2},{3,4}};
    int i,j;
    for (i=0;i<2;i++)
        for (j=0;j<2;j++)
            printf("%d\n",mat[i][j]);

    system("pause");
}


int main()
{
    int mat[2][2] = {{1,2},{3,4}};
    int *p = &mat[0][0];
    int i;
        for (i=0;i<4;i++)
        printf("%d\n",*(p+i));

    system("pause");
}

int main(){
    int i=3,j=5, random;
    int *p, *q;
    p = &i;
    q = &j;

    random = 3* - *p/(*q)+7;
    i = j = 1;
    //printf ("%d %d",i, j);

}

int F1 ( unsigned int n);
int F2 ( unsigned int n);
int similar (unsigned int n);

int main()
{
    unsigned int n;
    int retorno, simila, efe2;

    printf ("BOTA O N: ");
    scanf ("%d",&n);

    retorno = F1(n);
    simila = similar(n);    
    efe2 = F2(n);
    printf ("\nF1: %d\nSIMILAR: %d\nF2: %d",retorno,simila,efe2);
}

int F1 ( unsigned int n)
    {
    if(n==0) return n;
    int i , j;
    for ( i = j = 1; i<2 *n-1 ; i+=2, j +=i);
    return j;
    }

int similar (unsigned int n)
{
    if (n==0) return n;
    int i, j, retorno=0;
    for (i=0; i<n; i++)
        retorno += n;
    return retorno;
}

int F2 ( unsigned int n)
{
if(n==0) return n;
int i , j, muquinha;
for ( i = j = 1; i<2 *n-1 ; i+=2)
for ( muquinha=0 ; i<0;  j +=i);
return j;
}


int main() {
int i = 5, *p;
p = &i;
printf("%p %d %d %d %d \n", p, *p+2, **&p, 3**p, **&p+4);
}
*/
int main ()
{
    int mat[4], *p, x;
    mat[0] = 1;
    mat[1] = 2;
    mat[2] = 3;
    mat[3] = 4;
    
    //p = mat + 1;
    //p = mat++;
    //p = ++mat;
    x = (*mat)++;
}