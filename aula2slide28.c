#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    int idade;
    int altura;
}Pessoa;

int main(){
    int *opc, *qnt;
    opc = (int *)malloc(sizeof(int));
    qnt = (int *)malloc(sizeof(int));
    *opc = 1;
    *qnt = 0;
//aloca um espaço de memoria do tamanho da struct e da o endereço ao ponteiro
    Pessoa *p;
    p = (Pessoa *)malloc(sizeof(Pessoa));

    while (*opc==1)
    {
    //le os dados da pessoa
        printf ("Nome: ");
        scanf ("%[^\n]",&p[*qnt].nome);
        printf ("Idade: ");
        scanf ("%d",&p[*qnt].idade);
        printf ("Altura: ");
        scanf ("%d",&p[*qnt].altura);

        printf ("Deseja adicionar mais uma pessoa? (1.Sim 2.Nao): ");
        scanf ("%d",&*opc);
        getchar();

        if (*opc==1)
        {
            (*qnt)++;
            p = realloc(p, sizeof(Pessoa) * (*qnt+1));
        }
    }

    //imprime os dados na tela
    for (int i=0; i<=(*qnt); i++)
    {
        printf ("\nNome: %s\n",p[i].nome);
        printf ("Idade: %d\n",p[i].idade);
        printf ("Altura: %d\n",p[i].altura);
    }

    //NAO ESQUECER DE LIBERAR A MEMORIA ALOCADA
free(p);
free(opc);
free(qnt);
return 0;
} 