#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int cod;
    char nome[40];
    float preco;
}SProduto;

typedef struct sNodo{
    SProduto info;
    struct sNodo *pNext;
}SNodo;

typedef struct{
    SNodo *pFirst;
    SNodo *pLast;
}SFila;

int menu (void);
void Clear (SFila *pFila);
void Reset (SFila *pFila);
void Push (SFila *pFila, SProduto *pProd);
void Pop (SFila *pFila, SProduto *pProd);
void List (SFila *pFila);

int main ()
{
    int o=0;
    SFila *pFila;
    SProduto *pProd;

    pFila = (SFila *)malloc(sizeof(SFila));
    pFila->pFirst = NULL;
    pFila->pLast = NULL;


    while (o != 5)
    {
        o = menu();
        switch (o)
        {
            case 1:
                Reset(pFila);
                break;
            case 2:
                pProd = (SProduto *)malloc(sizeof(SProduto));
                
                printf ("Codigo do produto: ");
                scanf ("%d",&pProd->cod);
                setbuf(stdin,NULL);
                printf ("Nome do produto: ");
                scanf ("%[^\n]",pProd->nome);
                printf ("Preco do produto: ");
                scanf ("%f",&pProd->preco);
                Push (pFila, pProd);

                free(pProd);
                break;
            case 3:
                pProd = (SProduto *)malloc(sizeof(SProduto));

                Pop(pFila, pProd);
                printf ("COD: %d, %s, R$%.2f\n",pProd->cod,pProd->nome,pProd->preco);

                free(pProd);
                break;
            case 4:
                List(pFila);
                break;
            case 5:
                Clear(pFila);
                exit(0);
                break;
        }
    }
return 0;
}

int menu (void)
{
    int o;
    printf ("AULA 6 - FILA - EH O GUTHS\n");
    printf ("1. Cria fila nova e apaga a antiga\n");
    printf ("2. Adiciona produto na fila\n");
    printf ("3. Retira produto da fila\n");
    printf ("4. Lista na tela os produtos\n");
    printf ("5. Sair do programa\n");
    printf ("Opcao: ");
    scanf ("%d",&o);
    return o;
}

void Reset (SFila *pFila)
{
    Clear (pFila);
    pFila = (SFila *)malloc(sizeof(SFila));
    pFila->pFirst = NULL;
    pFila->pLast = NULL;
}

void Clear (SFila *pFila)
{
    SNodo *atual, *prox;
    if (pFila->pFirst != NULL)
    {
        atual = pFila->pFirst;
        prox = atual->pNext;

        while (prox != NULL)
        {
            free(atual);
            atual = prox;
            prox = prox->pNext;
        }
        free(atual);
    }
    free(pFila);
}

void Push (SFila *pFila, SProduto *pProd)
{
    SNodo *nNodo;
    nNodo = (SNodo *)malloc(sizeof(SNodo));

    nNodo->info = *pProd;
    nNodo->pNext = NULL;

    if (pFila->pLast == NULL)
        pFila->pFirst = nNodo;
    else
        pFila->pLast->pNext = nNodo;

    pFila->pLast = nNodo;
}

void Pop (SFila *pFila, SProduto *pProd)
{
    SNodo *aux;

    if (pFila->pFirst == NULL)
        printf ("Fila vazia!\n");
    else
    {
        aux = pFila->pFirst;
        *pProd = pFila->pFirst->info;
        pFila->pFirst = pFila->pFirst->pNext;
        free(aux);

        if (pFila->pFirst == NULL)
            pFila->pLast = NULL;
    }
}

void List (SFila *pFila)
{
    SNodo *aux;

    if (pFila->pFirst == NULL)
        printf ("Fila vazia!\n");
    else
    {
        for (aux = pFila->pFirst; aux != NULL; aux = aux->pNext)
            printf ("COD: %d, %s, R$%.2f\n",aux->info.cod,aux->info.nome,aux->info.preco);
    }
}