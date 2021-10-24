#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max;
    int i,j;
   do
    {
        printf("Bonjour, Donnez moi un nombre (max) pour recherche \net compte tous les triplets pythagoriciens (x,y,z)\ntels que 1<=x<=y<=max, \n");
        printf("(0 ou negatif) pour quitter\n");
        printf("max : ");
        scanf("%d",&max);
        if(max>=0)
        {
            for(i=0;i<=max;i++)
                for(j=0;j<=max;j++)
                {
                    printf("(%d,%d,%d)\n",i,j,i*i+j*j);;
                }
        }
    }while(max>=0);
    return 0;
}
