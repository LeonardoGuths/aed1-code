#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int ra;
    char nome[50];
}Aluno;

typedef struct
{
    Aluno *alunos;
    Aluno *topo;
    Aluno *base;
    int limite;
}Pilha;

int menu (void);
void RESET (Pilha *p);
void PUSH (Pilha *p, Aluno *novo);
unsigned int POP (Pilha *p, Aluno *popado);
unsigned int EMPTY (Pilha *p);
unsigned int FULL (Pilha *p);

int main()
{
    Pilha *p;
    Aluno *item;
    int opc=0;
    unsigned int popou=0, fakeboolean=0;

    p = (Pilha *)malloc(sizeof(Pilha));
    RESET(p);

    while (opc != 6)
    {
        opc = menu();
        switch(opc)
        {
            case 1:
                RESET(p);
                break;
            case 2:
                item = (Aluno *)malloc(sizeof(Aluno));

                setbuf (stdin, NULL);
                printf ("Nome do aluno: ");
                scanf ("%[^\n]",item->nome);
                printf ("RA do aluno: ");
                scanf ("%d",&item->ra);
                PUSH(p, item);

                free(item);
                break;
            case 3:
                item = (Aluno *)malloc(sizeof(Aluno));

                popou = POP(p, item);
                if (popou == 1)
                    printf ("%s, RA: %d\n",item->nome,item->ra);
                
                popou = 0;
                free(item);
                break;
            case 4:
                fakeboolean = EMPTY(p);
                if (fakeboolean == 1)
                    printf ("TA VAZIA\n");
                break;
            case 5:
                fakeboolean = FULL(p);
                if (fakeboolean == 1)
                    printf ("claro q ta cheia, so aloca espaco quando precisa...\n");
                break;
            case 6:
                free(p->alunos);
                free(p);
                exit(0);
                break;
        }
    }

}

int menu (void)
{
    int o;
    printf ("TESTE DE PILHA - EH O GUTHS\n");
    printf ("1. RESET\n");
    printf ("2. PUSH\n");
    printf ("3. POP\n");
    printf ("4. EMPTY (desativado)\n");
    printf ("5. FULL (desativado)\n");
    printf ("6. EXIT\n");
    printf ("Opcao: ");
    scanf ("%d",&o);
    return o;
}

void RESET (Pilha *p)
{
    p->alunos = NULL;
    p->topo = NULL;
    p->base = NULL;
    p->limite = 0;
}

void PUSH (Pilha *p, Aluno *novo)
{
    p->limite++;
    if (p->limite == 1)
        p->alunos = (Aluno *)malloc(sizeof(Aluno) * p->limite);
    else
        p->alunos = realloc(p->alunos, sizeof(Aluno) * p->limite);

    
    p->alunos[p->limite-1] = *novo;

    if (p->limite == 1)
        p->base = &p->alunos[0];
    
    p->topo = &p->alunos[p->limite-1];
}

unsigned int POP (Pilha *p, Aluno *popado)
{
    if (p->limite == 0)
    {
        free(p->alunos);
        RESET(p);
        return 0;
    }
    else
    {
        *popado = *(p->topo);
        p->limite--;

        if (p->limite > 0)
        {
            p->alunos = realloc(p->alunos, sizeof(Aluno) * p->limite);
            p->topo = &p->alunos[p->limite-1];
            return 1;
        }
        else
        {
            free(p->alunos);
            RESET(p);
            return 1;
        }
    }
}

unsigned int EMPTY (Pilha *p)
{
    if (p->limite == 0)
        return 1;
    else
        return 0;
}

unsigned int FULL (Pilha *p)
{
    if (p->topo == p->limite)
        return 1;
    else
        return 0;
}
