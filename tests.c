#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
    char p1[50], p2[50];
    int q;

    printf ("digite a primeira: ");
    scanf ("%[^\n]",p1);
    setbuf(stdin,NULL);
    printf ("digite a segunda: ");
    scanf ("%[^\n]",p2);
    q = strcmp(p1, p2);
    if ((strcmp(p1, p2)) == 0)
        printf ("iguais %d\n",q);
    else
        printf ("diferentes %d\n",q);
    
system ("pause");
}