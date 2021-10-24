#include <stdio.h>
#include <stdlib.h>

long somme = 0;

void diviseurs(int n)
 {
 	int i;
    printf("deviseurs de %d = { ",n);
    for(i=1;i<=n;i++)
    {
        if(n%i == 0)
        {
            printf("%d ",i);
            somme = somme + i;
        }
    }
    printf("}\n");
 }

void classification(int n)
 {
     diviseurs(n);
     system("cls");
     if(n == somme)
     {
        printf("%d est parfait\n\n\n",n);
     }
    else
        if(n > somme)
            {
                printf("%d est deficient\n\n\n",n);
            }
        else
            {
                printf("%d est abondant\n\n\n",n);
            }
 }

int main()
{
    int n;
    diviseurs(6);
    diviseurs(17);
    diviseurs(36);
    do
    {
        printf("Donnez moi un nombre\n");
        printf("(0) pour quitter\n");
        printf("n : ");
        scanf("%d",&n);
        classification(n);
    }while(n!=0);
    return 0;
}
