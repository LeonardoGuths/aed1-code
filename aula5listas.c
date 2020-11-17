#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int calorias;
}Alimento;

typedef struct{
    Alimento *info;
    Nodo *pNext;
}Nodo;

typedef struct{
    Nodo *pFirst;
}Lista;

void Clear (Lista *pLista);
void Reset (Lista *pLista);

int main()
{
    Lista *pLista;
    Reset(pLista);

}

void Reset (Lista *pLista)
{
    Clear (pLista);
    pLista = (Lista *)malloc(sizeof(Lista));
}

void Clear (Lista *pLista)
{
    Nodo *atual, *prox;

    atual = pLista->pFirst;
    prox = atual->pNext;

    while (prox != NULL)
    {
        free(atual);
        atual = prox;
        prox = atual->pNext;
    }
    free(atual);
    free(pLista);
}