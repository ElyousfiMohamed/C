#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A;
    do
    {
        printf("Bonjour, Donnez moi une annee pour vous dire s il est bissextile ou non\n");
        printf("(0) pour quitter\n");
        printf("A : ");
        scanf("%d",&A);
        if((A%4 == 0 && A%100 != 0) || (A%400 == 0))
        {
            printf("%d est bissextile\n",A);
        }
        else
        {
            printf("%d n est pas bissextile\n",A);
        }
    }while(A!=0);
    return 0;
}
