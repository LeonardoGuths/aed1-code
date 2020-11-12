#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[30];
    int idade;
}Pessoa;

typedef struct
{
    Pessoa *ppl;
    Pessoa *topo;
    Pessoa *base;
    int limite;
}Pilha;

int menu (void);
void RESET (Pilha *p);
void PUSH (Pilha *p, Pessoa *nova);
unsigned int POP (Pilha *p, Pessoa *popada);
void POPname (Pilha *p, char *nome);
void CLEAR (Pilha *p);
void LIST (Pilha *p);

int main()
{
    int opc=0;
    Pessoa *item;
    Pilha *p;
    char *nome;

    p = (Pilha *)malloc(sizeof(Pilha));
    RESET(p);

    while (opc!=5)
    {
        opc = menu();
        switch(opc)
        {
            case 0:
                item = (Pessoa *)malloc(sizeof(Pessoa));

                setbuf(stdin,NULL);
                printf ("Nome: ");
                scanf ("%[^\n]",item->nome);
                printf ("Idade: ");
                scanf ("%d",&item->idade);

                PUSH(p, item);
                free(item);
                break;
            case 1:
                POP(p, item);
                break;
            case 2:
                nome = (char *)malloc(sizeof(char) * 30);

                setbuf(stdin,NULL);
                printf ("Qual nome: ");
                scanf ("%[^\n]",nome);

                POPname(p, nome);

                free(nome);
                break;
            case 3:
                CLEAR(p);
                break;
            case 4:
                LIST(p);
                break;
            case 5:
                free(p->ppl);
                free(p);
                exit(0);
                break;
        }
    } 
}

int menu (void)
{
    int o;
    printf ("EXE AULA 4 - EH O GUTHS\n");
    printf ("0. Insere pessoa\n");
    printf ("1. Deleta pessoa do topo\n");
    printf ("2. Deleta pessoa por nome\n");
    printf ("3. Limpa a pilha\n");
    printf ("4. Lista na tela as pessoas\n");
    printf ("5. Sair do programa\n");
    printf ("Opcao: ");
    scanf ("%d",&o);
    return o;
}

void RESET (Pilha *p)
{
    p->ppl = NULL;
    p->topo = NULL;
    p->base = NULL;
    p->limite = 0;
}

void PUSH (Pilha *p, Pessoa *nova)
{
    p->limite++;
    if (p->limite == 1)
        p->ppl = (Pessoa *)malloc(sizeof(Pessoa) * p->limite);
    else
        p->ppl = realloc(p->ppl, sizeof(Pessoa) * p->limite);

    
    p->ppl[p->limite-1] = *nova;

    if (p->limite == 1)
        p->base = &p->ppl[0];
    
    p->topo = &p->ppl[p->limite-1];
}

unsigned int POP (Pilha *p, Pessoa *popada)
{
    if (p->limite == 0)
    {
        free(p->ppl);
        RESET(p);
        return 0;
    }
    else
    {
        *popada = *(p->topo);
        p->limite--;

        if (p->limite > 0)
        {
            p->ppl = realloc(p->ppl, sizeof(Pessoa) * p->limite);
            p->topo = &p->ppl[p->limite-1];
            return 1;
        }
        else
        {
            free(p->ppl);
            RESET(p);
            return 1;
        }
    }
}

void POPname (Pilha *p, char *nome)
{
    Pilha *pAux;
    int i, popo=0;

    pAux = (Pilha *)malloc(sizeof(Pilha));
    RESET(pAux);

    pAux->ppl = (Pessoa *)malloc(sizeof(Pessoa));

    for (i=0; i < p->limite; i++)
    {
        popo = POP (p, &pAux->ppl[i]);
        if (popo == 1)
        {
            if (strcmp(pAux->ppl[i].nome, nome))
            {
                
            }
        }
    }
}