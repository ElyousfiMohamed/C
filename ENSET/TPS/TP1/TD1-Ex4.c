#include <stdio.h>
#include <stdlib.h>

long fact(int n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}

int main()
{
    /*int n; //calcul de n!
    do
    {
        printf("Bonjour, Donnez moi un nombre (n) pour calculer son factoriel \n");
        printf("(negatif) pour quitter\n");
        printf("n : ");
        scanf("%d",&n);
        if(n>=0)
        {
            printf("%d! = %d\n\n\n",n,fact(n));
        }
    }while(n>=0);*/

    for(int i=0;i<=10;i++)
        printf("%d! = %d\n\n",i,fact(i));
}
