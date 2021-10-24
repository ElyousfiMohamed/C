#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//l'ensemble des fonctions qu'on va calculer leur integrale sur [a,b]
float F_expX(float x)
{
    return exp(x);
}

float F_carreX(float x)
{
    return x*x;
}

float F_sqrtX(float x)
{
    return sqrt(x);
}

//fonction qui calcule l'integrale
float integrale_F(float (*p)(float))
{
    float intgr = 0,a,b,h;
    long n;//n nombre des sous-intervales
    int i;
    printf("saisi de l'intervale[a,b]\n");
    printf("a : ");
    scanf("%f",&a);
    printf("b : ");
    scanf("%f",&b);
    printf("\n\nnombre des sous-intervales\n");
    printf("n : ");
    scanf("%ld",&n);
    h = (b-a)/n;
    for(i=1;i<n;i++)
    {
        intgr = intgr + p(a+i*h);
    }
    intgr = (2.0*intgr + p(a) + p(b)) * h/2.0;
    return intgr;
}

int main()
{
    float (*p)(float); //pointeur qui points vers le differents fonctions definie deja
    int choix;
    do
    {
        printf("tapez :\n   (0) pour calcule integrale de exp(x)");
        printf("\n   (1) pour calcule integrale de x^2");
        printf("\n   (2) pour calcule integrale de sqrt(x)");
        printf("\n   (3) pour quitter\n\n");
        printf("choix : ");
        scanf("%d",&choix);
        switch(choix)
        {
        case 0 :
            p=F_expX;
            printf("integrale exp(x) = %f\n",integrale_F(p));
            break;
        case 1 :
            p=F_carreX;
            printf("integrale x^2 = %f\n",integrale_F(p));
            break;
        case 2 :
            p=F_sqrtX;
            printf("integrale sqrt(x) = %f\n",integrale_F(p));
            break;
    }
    system("pause");
    system("cls");
    }while (choix != 3);
    return 0;
}
