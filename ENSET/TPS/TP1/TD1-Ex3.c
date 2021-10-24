#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,Som_carres;
    do
    {
        printf("Bonjour, Donnez moi un nombre (n) pour afficher la somme Som_carres = 1+4+...+n^2 \n");
        printf("(0) pour quitter\n");
        printf("n : ");
        scanf("%d",&n);
        if(n>=0)
        {
            printf("Somme carres = %d\n\n\n",(n*(n + 1)*(2*n + 1))/6);
        }
    }while(n!=0);
    return 0;
}
