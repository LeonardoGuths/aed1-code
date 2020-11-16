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
}Controle;

void menu (int o);
void insere (Controle *c);

int main()
{
    void *pBuffer;
    pBuffer = malloc(sizeof(Controle));

    pBuffer->opc =0;

    while (pBuffer->opc != 5)
    {
        menu(pBuffer->opc);
        switch (pBuffer->opc)
        {
            case 1:
                insere(pBuffer);
        }

    }

}

void menu (int o)
{
    printf ("AULA 1 SLIDE 28 - EH O GUTHS\n");
    printf ("1. Inserir pessoa\n");
    printf ("2. Apagar pessoa\n");
    printf ("3. Buscar pessoa\n");
    printf ("4. Listar pessoas\n");
    printf ("5. Sair do programa\n");
    printf ("Opcao: ");
    scanf ("%d",&o);
}
