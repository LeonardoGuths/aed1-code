#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *opc;
char *nomes;

void menu (void);
void adicionar (void);
void remover (void);
void listar (void);

int main(){

    opc = (int *)malloc(sizeof(int));
    nomes = (char *)malloc(sizeof(char));
    *opc = 0;
    strcpy(nomes, "\0");
    while (*opc != 4)
    {
        menu();
        switch (*opc){
            case 1:
                adicionar();
                break;
            case 2:
                remover();
                break;
            case 3:
                listar();
                break;
            case 4:
                free (opc);
                free (nomes);
                exit(0);
                break;
        }
    }
return 0;
}

void menu (void){
    printf ("1) Adicionar nome\n");
    printf ("2) Remover nome\n");
    printf ("3) Listar\n");
    printf ("4) Sair\n");
    printf ("Opcao: ");
    scanf ("%d",&(*opc));
    getchar();
}

void adicionar (void){
    char n[50], *end;
    int t;

    printf ("Insira um nome: ");
    scanf ("%[^\n]",n);

    t = strlen(n);
    end = realloc(nomes, _msize(nomes) + (sizeof(char) * (t+2)) );
    if (end != NULL)
        nomes = end;
    strcat(nomes, n);
    strcat(nomes, "-");
}

void remover(void){
    int rmv, i=0, trmv;
    char *tkn, *tmp, *nova, *x;

    tmp = (char *)malloc(_msize(nomes));

    memcpy(tmp, nomes, _msize(nomes));
    tkn = strtok(tmp, "-");

    printf ("Qual nome deseja remover? \n");
    while (tkn != NULL)
    {
        printf ("%d.%s ",i,tkn);
        tkn = strtok(NULL, "-");
        i++;
    }
    printf ("\nNumero: ");
    scanf ("%d",&rmv);

    memcpy(tmp, nomes, _msize(nomes));
    tkn = strtok(tmp, "-");

    for (i=0; tkn != NULL; i++)
    {
        if (i == rmv)
        {
            trmv = strlen(tkn) * sizeof(char);
        }
        tkn = strtok(NULL, "-");
    }
    nova = (char *)malloc(_msize(nomes) - (trmv + sizeof(char)));
    strcpy (nova, "\0");

    memcpy(tmp, nomes, _msize(nomes));
    tkn = strtok(tmp, "-");

    for (i=0; tkn != NULL; i++)
    {
        if (i != rmv)
        {
            strcat(nova, tkn);
            strcat(nova, "-");
        }
        tkn = strtok(NULL, "-");
    }

    x = nomes;
    nomes = nova;
    free (x);
    free (tmp);
}

void listar (void){
    char *tkn, *tmp;
    int i=0;

    tmp = (char *)malloc(_msize(nomes));
    memcpy(tmp, nomes, _msize(nomes));

    tkn = strtok(tmp, "-");
    while (tkn != NULL)
    {
        printf ("%d.%s ",i,tkn);
        tkn = strtok(NULL, "-");
        i++;
    }
    printf ("\n");
    free (tmp);
}