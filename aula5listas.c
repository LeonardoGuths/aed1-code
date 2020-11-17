#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    float peso;
    int calorias;
}Alimento;

typedef struct sNodo{
    Alimento info;
    struct sNodo *pNext;
}Nodo;

typedef struct{
    Nodo *pFirst;
}Lista;

int menu (void);
void Clear (Lista *pLista);
void Reset (Lista *pLista);
int Push (Lista *pLista, Nodo *pNodo, int index);
//void Pop (Lista *pLista, int index);
void List (Lista *pLista);

int main()
{
    int o=0, index;
    Nodo *pNodo;
    Lista *pLista;

    pLista = (Lista *)malloc(sizeof(Lista));
    pLista->pFirst = NULL;


    while (o != 5)
    {
        o = menu();
        switch (o)
        {
            case 1:
                Reset(pLista);
                break;
            case 2:
                pNodo = (Nodo *)malloc(sizeof(Nodo));

                setbuf(stdin,NULL);
                printf ("Nome do alimento: ");
                scanf ("%[^\n]",pNodo->info.nome);
                printf ("Peso (em gramas): ");
                scanf ("%f",&pNodo->info.peso);
                printf ("Calorias (em kcal): ");
                scanf ("%d",&pNodo->info.calorias);
                printf ("Inserir em qual index: ");
                scanf ("%d",&index);

                Push(pLista, pNodo, index);
                break;
                /*
            case 3:
                Pop(pLista, index);
                break;
                */
            case 4:
                List(pLista);
                break;
            case 5:
                Clear(pLista);
                exit(0);
                break;
        }
    }
return 0;
}

int menu (void)
{
    int o;
    printf ("AULA 5 - LISTA ENCADEADA - EH O GUTHS\n");
    printf ("1. Cria lista nova e apaga a antiga\n");
    printf ("2. Adiciona alimento na lista\n");
    printf ("3. Retira alimento da lista\n");
    printf ("4. Lista na tela os alimentos\n");
    printf ("5. Sair do programa\n");
    printf ("Opcao: ");
    scanf ("%d",&o);
    return o;
}

void Reset (Lista *pLista)
{
    Clear (pLista);
    pLista = (Lista *)malloc(sizeof(Lista));
    pLista->pFirst = NULL;
}

void Clear (Lista *pLista)
{
    Nodo *atual, *prox;
    if (pLista->pFirst != NULL)
    {
        atual = pLista->pFirst;
        prox = atual->pNext;

        while (prox != NULL)
        {
            free(atual);
            atual = prox;
            prox = prox->pNext;
        }
        free(atual);
    }
    free(pLista);
}

int Push (Lista *pLista, Nodo *pNodo, int index)
{
    Nodo *anterior, *atual;
    int pos;

    if (pLista->pFirst == NULL && index != 0)
        return 0;   //indice invalido
    else if (pLista->pFirst == NULL && index == 0)
    {
        pLista->pFirst = pNodo;
        pLista->pFirst->pNext = NULL;
        return 1;
    }
    else if (index == 0)
    {
        pNodo->pNext = pLista->pFirst;
        pLista->pFirst = pNodo;
        return 1;
    }

    atual = pLista->pFirst;
    for (pos = 0; pos < index && atual != NULL; pos++)
    {
        anterior = atual;
        atual = atual->pNext;
    }

    if (atual == NULL)
    {
        printf ("INDICE INVALIDO\n");
        return 0;
    }
    
    pNodo->pNext = atual;
    anterior->pNext = pNodo;
}

void List (Lista *pLista)
{
    Nodo *atual;
    atual = pLista->pFirst;

    if (atual != NULL)
    {
        while(atual != NULL)
        {
            printf ("%s, %.2fg, %dkcal\n",atual->info.nome,atual->info.peso,atual->info.calorias);
            atual = atual->pNext;
        }
    }
    else
        printf ("Lista vazia!\n");
}