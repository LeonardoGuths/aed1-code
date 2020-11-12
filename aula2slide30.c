#include <stdio.h>
#include <stdlib.h>

int ** criaMatriz(int m, int n);
void leiaMatriz(int **mat, int m, int n);
int somaMatriz(int **mat, int m, int n);
int* colunaMatriz(int ** mat, int m, int n, int ncoluna);
void liberaMatriz(int **mat, int m);
void imprimeMatriz(int **mat, int m, int n);
void imprimeVetor (int *vet, int m);

int main()
{
    int opc=0, m=0, n=0, **M, *vet, soma, ncoluna;

    while (opc!=6)
    {
        printf ("1) Criar e redimensionar uma matriz m x n\n");
        printf ("2) Realizar a leitura dos elementos da matriz\n");
        printf ("3) Fornecer a soma dos elementos da matriz\n");
        printf ("4) Retornar em um vetor (utilizando ponteiros) os elementos de uma determinada coluna da matriz\n");
        printf ("5) Imprimir a matriz\n");
        printf ("6) Sair do programa\n");
        printf ("Opcao: ");
        scanf ("%d",&opc);
            switch (opc)
            {
            case 1:
                liberaMatriz(M, m);
                printf("Linhas (m): ");
                scanf ("%d",&m);
                printf("Colunas (n): ");
                scanf ("%d",&n);
                 M = criaMatriz(m, n);
                break;
            case 2:
                leiaMatriz(M, m, n);
                break;
            case 3:
                soma = somaMatriz(M, m, n);
                printf ("Soma dos elementos da matriz: %d\n",soma);
                printf ("\nPressione enter para retornar ao menu...\n");
                setbuf(stdin, NULL);
                getchar();
                break;
            case 4:
                printf ("Numero da coluna: ");
                scanf ("%d",&ncoluna);
                vet = colunaMatriz(M, m, n, ncoluna);
                imprimeVetor(vet, m);
                free (vet);
                break;
            case 5:
                imprimeMatriz(M, m, n);
                break;
                
            case 6:
                liberaMatriz(M, m);
                exit(0);
                break;
                
        }
    }

return 0;
}

int ** criaMatriz(int m, int n)
{
    int **matriz, i;

        matriz = (int **)malloc(sizeof(int *) * m);
        for (i=0; i<m; i++)
            matriz[i] = (int *)malloc(sizeof(int) * n);

    return matriz;
}

void leiaMatriz(int **mat, int m, int n)
{
    int l, c;
    if (m!=0 && n!=0 && mat!=NULL)
    {
        for (l=0; l<m; l++)
            for (c=0; c<n; c++)
            {
                printf ("M[%d][%d] = ",l,c);
                scanf("%d",&mat[l][c]);
            }
    }
    else
        printf("Erro na matriz!\n");
    
}

int somaMatriz(int **mat, int m, int n)
{
    int l, c, soma=0;
    for (l=0; l<m; l++)
        for (c=0; c<n; c++)
            soma += mat[l][c];

    return soma;
}

int* colunaMatriz(int ** mat, int m, int n, int ncoluna)
{
    int *vet, i;
    vet = (int *)malloc(sizeof(int) * m);

    for (i=0; i<m; i++)
        vet[i] = mat[i][ncoluna];
    
    return vet;
}

void imprimeVetor (int *vet, int m)
{
    printf ("\n\n\n\n\n\n");
    for (int i=0; i<m; i++)
        printf ("%d\n",vet[i]);
    
    printf ("\nPressione enter para retornar ao menu...\n");
    setbuf(stdin, NULL);
    getchar();
}

void imprimeMatriz(int **mat, int m, int n)
{
    int l, c;
    printf ("\n\n\n\n\n\n");
    //system("cls");

    for (l=0; l<m; l++)
    {
        for (c=0; c<n; c++)
            printf ("%d ",mat[l][c]);

        printf ("\n");
    }
    printf ("\nPressione enter para retornar ao menu...\n");
    setbuf(stdin, NULL);
    getchar();
}

void liberaMatriz(int **mat, int ncoluna)
{
    if (ncoluna!=0 && mat!=NULL)
    {
        for (int i=0; i<ncoluna; i++)
            free (mat[i]);
        
        free (mat);
    }
}