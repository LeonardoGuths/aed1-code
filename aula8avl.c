#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int Chave;
    /*conteudo do no*/
}Registro;

typedef struct tno{
    Registro Reg;
    struct tno *pEsq, *pDir;
}No;

int Altura (No *pRaiz);
int FB (No *pRaiz);
void RSD (No **ppRaiz);
void RSE (No **ppRaiz);
int Balanceamento (No **ppRaiz);
int balanceaEsq (No **ppRaiz);
int balanceaDir (No **ppRaiz);
int Insere (No **ppRaiz, Registro x);
int EhAVL(No* pRaiz);
void freeAVL(No **pRaiz);
void freeNodos (No *ppRaiz);

int main()
{
    int i, n;
    Registro x;
    No **ppArv;
    Registro casosdeteste[11];

    ppArv = (No **)malloc(sizeof(No));
    *ppArv = NULL;

    printf ("Quantos nos deseja na arvore aleatoria: ");
    scanf ("%d",&n);

    srand(time(0));
    printf ("Testes cada vez que insere um novo numero na arvore aleatoria:\n");
    for (int i=0; i<n; i++)
    {
        x.Chave = rand();
        Insere (ppArv, x);
        printf ("Insercao aleatoria %d: ",i+1);
        if (EhAVL(*ppArv))
            printf ("EH AVL\n");
        else
            printf ("NAO EH AVL\n");
    }
    printf ("Teste final da arvore aleatoria: ");
    if (EhAVL(*ppArv))
        printf ("EH AVL\n");
    else
        printf ("NAO EH AVL\n");

    freeAVL(ppArv);
    printf ("________________________________________\n");

//--------------------------------------------------------------------
//Arvore do caso 1A
    casosdeteste[0].Chave = 20;
    casosdeteste[1].Chave = 4;
    casosdeteste[2].Chave = 15;

    printf ("[Caso 1A]\n");
    for (i=0; i<3; i++)
    {
        printf ("Insere %d: ",casosdeteste[i].Chave);
        Insere (ppArv, casosdeteste[i]);
        if (EhAVL(*ppArv))
            printf ("EH AVL\n");
        else
            printf ("NAO EH AVL\n");
    }

    printf ("Teste final [Caso 1A]: ");
    if (EhAVL(*ppArv))
        printf ("EH AVL\n");
    else
        printf ("NAO EH AVL\n");

    freeAVL(ppArv);
    printf ("________________________________________\n");

//--------------------------------------------------------------------
//Arvore do caso 2A
    casosdeteste[0].Chave = 20;
    casosdeteste[1].Chave = 4;
    casosdeteste[2].Chave = 26;
    casosdeteste[3].Chave = 3;
    casosdeteste[4].Chave = 9;
    casosdeteste[5].Chave = 15;

    printf ("[Caso 2A]\n");
    for (i=0; i<6; i++)
    {
        printf ("Insere %d: ",casosdeteste[i].Chave);
        Insere (ppArv, casosdeteste[i]);
        if (EhAVL(*ppArv))
            printf ("EH AVL\n");
        else
            printf ("NAO EH AVL\n");
    }

    printf ("Teste final [Caso 2A]: ");
    if (EhAVL(*ppArv))
        printf ("EH AVL\n");
    else
        printf ("NAO EH AVL\n");

    freeAVL(ppArv);
    printf ("________________________________________\n");

//--------------------------------------------------------------------
//Arvore do caso 3A
    casosdeteste[0].Chave = 20;
    casosdeteste[1].Chave = 4;
    casosdeteste[2].Chave = 26;
    casosdeteste[3].Chave = 3;
    casosdeteste[4].Chave = 9;
    casosdeteste[5].Chave = 21;
    casosdeteste[6].Chave = 30;
    casosdeteste[7].Chave = 2;
    casosdeteste[8].Chave = 7;
    casosdeteste[9].Chave = 11;
    casosdeteste[10].Chave = 15;

    printf ("[Caso 3A]\n");
    for (i=0; i<11; i++)
    {
        printf ("Insere %d: ",casosdeteste[i].Chave);
        Insere (ppArv, casosdeteste[i]);
        if (EhAVL(*ppArv))
            printf ("EH AVL\n");
        else
            printf ("NAO EH AVL\n");
    }

    printf ("Teste final [Caso 3A]: ");
    if (EhAVL(*ppArv))
        printf ("EH AVL\n");
    else
        printf ("NAO EH AVL\n");

    freeAVL(ppArv);
    printf ("________________________________________\n");

//--------------------------------------------------------------------
//Arvore do caso 1B
    casosdeteste[0].Chave = 20;
    casosdeteste[1].Chave = 4;
    casosdeteste[2].Chave = 8;

    printf ("[Caso 1B]\n");
    for (i=0; i<3; i++)
    {
        printf ("Insere %d: ",casosdeteste[i].Chave);
        Insere (ppArv, casosdeteste[i]);
        if (EhAVL(*ppArv))
            printf ("EH AVL\n");
        else
            printf ("NAO EH AVL\n");
    }

    printf ("Teste final [Caso 1B]: ");
    if (EhAVL(*ppArv))
        printf ("EH AVL\n");
    else
        printf ("NAO EH AVL\n");

    freeAVL(ppArv);
    printf ("________________________________________\n");
    
//--------------------------------------------------------------------
//Arvore do caso 2B
    casosdeteste[0].Chave = 20;
    casosdeteste[1].Chave = 4;
    casosdeteste[2].Chave = 26;
    casosdeteste[3].Chave = 3;
    casosdeteste[4].Chave = 9;
    casosdeteste[5].Chave = 8;

    printf ("[Caso 2B]\n");
    for (i=0; i<6; i++)
    {
        printf ("Insere %d: ",casosdeteste[i].Chave);
        Insere (ppArv, casosdeteste[i]);
        if (EhAVL(*ppArv))
            printf ("EH AVL\n");
        else
            printf ("NAO EH AVL\n");
    }

    printf ("Teste final [Caso 2B]: ");
    if (EhAVL(*ppArv))
        printf ("EH AVL\n");
    else
        printf ("NAO EH AVL\n");

    freeAVL(ppArv);
    printf ("________________________________________\n");

//--------------------------------------------------------------------
//Arvore do caso 3B
    casosdeteste[0].Chave = 20;
    casosdeteste[1].Chave = 4;
    casosdeteste[2].Chave = 26;
    casosdeteste[3].Chave = 3;
    casosdeteste[4].Chave = 9;
    casosdeteste[5].Chave = 21;
    casosdeteste[6].Chave = 30;
    casosdeteste[7].Chave = 2;
    casosdeteste[8].Chave = 7;
    casosdeteste[9].Chave = 11;
    casosdeteste[10].Chave = 8;

    printf ("[Caso 3B]\n");
    for (i=0; i<11; i++)
    {
        printf ("Insere %d: ",casosdeteste[i].Chave);
        Insere (ppArv, casosdeteste[i]);
        if (EhAVL(*ppArv))
            printf ("EH AVL\n");
        else
            printf ("NAO EH AVL\n");
    }

    printf ("Teste final [Caso 3B]: ");
    if (EhAVL(*ppArv))
        printf ("EH AVL\n");
    else
        printf ("NAO EH AVL\n");

    freeAVL(ppArv);
    printf ("________________________________________\n");
    
free (ppArv);
return 0;
}

int Altura (No *pRaiz)
{
    int iesq, idir;

    if (pRaiz == NULL)
        return 0;
    
    iesq = Altura(pRaiz->pEsq);
    idir = Altura(pRaiz->pDir);

    if (iesq > idir)
        return iesq + 1;
    else
        return idir + 1;
}

int FB (No *pRaiz)
{
    if (pRaiz == NULL)
        return 0;
    
    return Altura(pRaiz->pEsq) - Altura(pRaiz->pDir);
}

void RSD (No **ppRaiz)
{
    No *aux;

    aux = (*ppRaiz)->pEsq;
    (*ppRaiz)->pEsq = aux->pDir;
    aux->pDir = *ppRaiz;
    *ppRaiz = aux;
}

void RSE (No **ppRaiz)
{
    No *aux;
    
    aux = (*ppRaiz)->pDir;
    (*ppRaiz)->pDir = aux->pEsq;
    aux->pEsq = (*ppRaiz);
    (*ppRaiz) = aux;
}

int Balanceamento (No **ppRaiz)
{
    int fb;
    fb = FB(*ppRaiz);
    if (fb > 1)
        balanceaEsq(ppRaiz);
    else if (fb < -1)
        balanceaDir(ppRaiz);
    else
        return 0;
}

int balanceaEsq (No **ppRaiz)
{
    int fbe;
    fbe = FB((*ppRaiz)->pEsq);
    if (fbe > 0)
    {
        /*FBRaiz ++ e FBEsq ++
        rotacao simples pra direita*/
        RSD(ppRaiz);
        return 1;
    }
    else if (fbe < 0)
    {
        /*FBRaiz ++ e FBEsq --
        rotacao dupla pra direita*/
        RSE(&(*ppRaiz)->pEsq);
        RSD(ppRaiz);
        return 1;
    }
    return 0;
}

int balanceaDir (No **ppRaiz)
{
    int fbd;
    fbd = FB((*ppRaiz)->pDir);
    if (fbd < 0)
    {
        /*FBRaiz -- e FBDir --
        rotacao simples pra esquerda*/
        RSE(ppRaiz);
        return 1;
    }
    else if (fbd > 0)
    {
        /*FBRaiz -- e FBDir ++
        rotacao dupla pra esquerda*/
        RSD(&(*ppRaiz)->pDir);
        RSE(ppRaiz);
        return 1;
    }
    return 0;
}

int Insere (No **ppRaiz, Registro x)
{
    if (*ppRaiz == NULL)
    {
        *ppRaiz = (No *)malloc(sizeof(No));
        if (*ppRaiz == NULL)
            exit(1);
        
        (*ppRaiz)->Reg = x;
        (*ppRaiz)->pEsq = NULL;
        (*ppRaiz)->pDir = NULL;
        return 1;
    }
    else if ((*ppRaiz)->Reg.Chave > x.Chave)
    {
        if (Insere(&(*ppRaiz)->pEsq, x))
        {
            if (Balanceamento(ppRaiz))
                return 0;
            else
                return 1;
        }
        else
            return 0;
    }
    else if ((*ppRaiz)->Reg.Chave < x.Chave)
    {
        if (Insere(&(*ppRaiz)->pDir, x))
        {
            if (Balanceamento(ppRaiz))
                return 0;
            else
                return 1;
        }
        else
            return 0;
    }
    else
    {
        printf ("Esse valor ja ta na arvore\n");
        return 0;
    }
}

int EhAVL(No* pRaiz)
{
    int fb;
    if (pRaiz == NULL)
        return 1;
    if (!EhAVL(pRaiz->pEsq))
        return 0;
    if (!EhAVL(pRaiz->pDir))
        return 0;

    fb = FB (pRaiz);

    if ( ( fb > 1 ) || ( fb < -1) )
        return 0;
    else
        return 1;
}

void freeAVL (No **ppRaiz)
{
    freeNodos(*ppRaiz);
    *ppRaiz = NULL;
    return;
}

void freeNodos (No *pRaiz)
{
    if (pRaiz == NULL)
        return;
    
    freeNodos(pRaiz->pEsq);
    freeNodos(pRaiz->pDir);

    free (pRaiz);
}