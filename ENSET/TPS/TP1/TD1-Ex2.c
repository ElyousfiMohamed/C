#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,Sn;
    do
    {
        printf("Bonjour, Donnez moi un nombre (n) pour afficher la somme Sn = 1+2+...+n \n");
        printf("(negative) pour quitter\n");
        printf("n : ");
        scanf("%d",&n);
        if(n>=0)
        {
            printf("Somme = %d\n\n\n",(n*(n+1))/2);
        }
    }while(n>=0);
    return 0;
}
