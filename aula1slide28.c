#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int idade;
    int cpf;
}Pessoa;

typedef struct{
    Pessoa *ppl;
    int indice;
    int opc;
    int i, j;
    char aux[50];
}Controle;

int menu (void);
void insere (Controle *b);
void apaga (Controle *b);
void busca (Controle *b);


int main()
{
    Controle *pBuffer;
    pBuffer = (Controle *)malloc(sizeof(Controle));
    pBuffer->opc = 0;
    pBuffer->indice = 0;

    while (pBuffer->opc != 5)
    {
        pBuffer->opc = menu();
        switch (pBuffer->opc)
        {
            case 1:
                insere(pBuffer);
                break;
            case 2:
                apaga(pBuffer);
                break;
            case 3:
                busca(pBuffer);
                break;
                /*
            case 4:
                lista(pBuffer);
                break;
                */
            case 5:
                free(pBuffer->ppl);
                free(pBuffer);
                exit(0);
                break;
        }

    }

}

int menu (void)
{
    int o;
    printf ("AULA 1 SLIDE 28 - EH O GUTHS\n");
    printf ("1. Inserir pessoa\n");
    printf ("2. Apagar pessoa\n");
    printf ("3. Buscar pessoa\n");
    printf ("4. Listar pessoas\n");
    printf ("5. Sair do programa\n");
    printf ("Opcao: ");
    scanf ("%d",&o);
    return o;
}

void insere (Controle *b)
{
    if (b->indice == 0)
        b->ppl = (Pessoa *)malloc(sizeof(Pessoa));
    else
        b->ppl = realloc(b->ppl, sizeof(Pessoa) * (b->indice + 1));

    setbuf(stdin,NULL);
    printf ("Nome: ");
    scanf ("%[^\n]",b->ppl->nome);
    printf ("Idade: ");
    scanf ("%d",&b->ppl->idade);    
    printf ("CPF: ");
    scanf ("%d",&b->ppl->cpf);

    b->indice++;
}

void apaga (Controle *b)
{
    if (b->indice != 0)
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

        for (b->i = b->j; b->i < b->indice - 1; b->i++)
        {
            b->ppl[b->i] = b->ppl[b->i + 1];
        }

        b->indice--;
        
        if (b->indice != 0)
            b->ppl = realloc (b->ppl, sizeof(Pessoa) * b->indice);
        else
            free(b->ppl);
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
}