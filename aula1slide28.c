#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
    long long int cpf;
}Pessoa;

typedef struct{
    Pessoa *ppl;
    int indice;
    int opc;
    int i, j;
    char aux[50];
}Controle;

void menu (Controle *pBuff);
void insere (Controle *b);
void apaga (Controle *b);
void busca (Controle *b);
void lista (Controle *b);

int main()
{
    void *pBuffer;
    pBuffer = malloc(sizeof(Controle));
    menu (pBuffer);
    return 0;
}

void menu (Controle *pBuff)
{
    pBuff->opc = 0;
    pBuff->indice = 0;

    while (pBuff->opc != 5)
    {
        printf ("AULA 1 SLIDE 28 - EH O GUTHS\n");
        printf ("1. Inserir pessoa\n");
        printf ("2. Apagar pessoa\n");
        printf ("3. Buscar pessoa\n");
        printf ("4. Listar pessoas\n");
        printf ("5. Sair do programa\n");
        printf ("Opcao: ");
        scanf ("%d",&pBuff->opc);

        switch (pBuff->opc)
        {
            case 1:
                insere(pBuff);
                break;
            case 2:
                apaga(pBuff);
                break;
            case 3:
                busca(pBuff);
                break;
            case 4:
                lista(pBuff);
                break;
            case 5:
                free(pBuff->ppl);
                free(pBuff);
                exit(0);
                break;
        }
    }
}

void insere (Controle *b)
{
    if (b->indice == 0)
        b->ppl = (Pessoa *)malloc(sizeof(Pessoa));
    else
        b->ppl = realloc(b->ppl, sizeof(Pessoa) * (b->indice + 1));

    setbuf(stdin,NULL);
    printf ("Nome: ");
    scanf ("%[^\n]",b->ppl[b->indice].nome);
    printf ("Idade: ");
    scanf ("%d",&b->ppl[b->indice].idade);    
    printf ("CPF: ");
    scanf ("%lld",&b->ppl[b->indice].cpf);

    b->indice++;
}

void apaga (Controle *b)
{
    if (b->indice > 0)
    {
        printf ("Nome da pessoa que deseja apagar: ");
        setbuf(stdin,NULL);
        scanf ("%[^\n]",b->aux);
        b->j = -1;

        for (b->i=0; b->i < b->indice && b->j == -1; b->i++)
        {
            if ((strcmp(b->aux, b->ppl[b->i].nome)) == 0)
                b->j = b->i;
        }

        if (b->j != -1)
        {
            for (b->i = b->j; b->i < b->indice - 1; b->i++)
            {
                b->ppl[b->i] = b->ppl[b->i + 1];
            }

            b->indice--;

            if (b->indice > 0)
                b->ppl = realloc (b->ppl, sizeof(Pessoa) * b->indice);
            else
                free(b->ppl);
        }
        else
        {
            printf ("Nao tem ninguem com esse nome na agenda!\n");
        }
        
    }
    else
    {
        printf ("Nao tem ninguem na agenda");
    }

}

void busca (Controle *b)
{
    printf ("Nome da pessoa que deseja buscar: ");
    setbuf(stdin,NULL);
    scanf ("%[^\n]",b->aux);
    b->j = -1;

    for (b->i = 0; b->i < b->indice && b->j == -1; b->i++)
    {
        if ((strcmp(b->aux, b->ppl[b->i].nome)) == 0)
        {
            printf ("\n%s\nIdade: %d\nCPF: %.11lld\n\n",b->ppl[b->i].nome,b->ppl[b->i].idade,b->ppl[b->i].cpf);
            b->j = 0;
        }
    }
    if (b->j == -1)
        printf ("Nao tem ninguem com esse nome na agenda!\n");
}

void lista (Controle *b)
{
    for (b->i = 0; b->i < b->indice; b->i++)
    {
        printf ("%s, Idade: %d, CPF: %.11lld\n",b->ppl[b->i].nome,b->ppl[b->i].idade,b->ppl[b->i].cpf);
    }
}