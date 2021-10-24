#include <stdio.h>
#include <stdlib.h>

int Cube(int a)
{
    return a*a*a;
}

int main()
{
    int nbr,somme,help,a,i;
    for(i=0;i<1000;i++)
    {
        somme = 0;
        a = i;
        do
        {
            help = a%10;
            somme = somme + Cube(help);
            a = a/10;
        }while(a != 0);
        if(somme == i)
        {
            printf("%d est un nombre d'armstrong\n",i);
        }
        else
        {
            printf("%d n'est pas un nombre d'armstrong\n",i);
        }
    }
    return 0;
}
