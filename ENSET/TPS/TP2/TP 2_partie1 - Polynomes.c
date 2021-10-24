#include <stdio.h>
#include <stdlib.h>

#define  DegM 1000 //la degrée max

struct polynomeT{
    int n; //degréé de polynome
    float a[DegM+1];
};

typedef struct polynomeT polynome;

polynome saisirPoly()
{
    int deg,i;
    polynome poly;
    poly.n=0; // on suppose que la degree initiale de polynome est 0

    //en initialise les coeficients a 0, et on demande au utilisateur a saisir les coeficients non nulls
    for(i=0;i<DegM+1;i++)
        poly.a[i] = 0;

    do{
        printf("veuillez donnez la degre du coefficient a saisir(1000 au max)\n(degree negatif pour s'arreter)\n");
        printf("degree : ");scanf("%d",&deg);
        if(deg>=0 && deg<=DegM)
        {
            printf("a%d = ",deg);scanf("%f",&poly.a[deg]);
            if(deg>poly.n)
                poly.n = deg; //m-a-j de degree de polynome
        }
    }while(deg>=0 && deg<=DegM);
    return poly;
}

polynome sommePoly(polynome p1,polynome p2)
{
    polynome pSomme;
    int i;
    pSomme.n = p1.n>=p2.n?p1.n:p2.n;
    for(i=0;i<=pSomme.n;i++)
    {
        pSomme.a[i]=p1.a[i]+p2.a[i];
    }
    return pSomme;
}

polynome soustractionPoly(polynome p1,polynome p2)
{
    polynome pSous;
    int i;
    pSous.n = p1.n>=p2.n?p1.n:p2.n;
    for(i=0;i<=pSous.n;i++)
    {
        pSous.a[i]=p1.a[i] - p2.a[i];
    }
    return pSous;
}

void changeSigne(polynome *poly)
{
	int i;
    for(i=0;i<=poly->n;i++)
    {
        poly->a[i]=-1*poly->a[i];
    }
}

void comparePoly(polynome p1,polynome p2)
{
    int egaux = 1,i;
    if(p2.n != p1.n)
    {
        printf("poly1 # poly2\n");
    }
    else
    {
        for(i=0;i<=p1.n;i++)
        {
            if(p1.a[i]!=p2.a[i])
            {
                printf("poly1 # poly2\n");
                egaux = 0;
                break;
            }
        }
        if(egaux = 1)
            printf("poly1 = poly2\n");
    }
}

polynome derivPoly(polynome poly)
{
    polynome pDrv;
    int i;
    pDrv.n = poly.n-1;
     for(i=1;i<=poly.n;i++)
        {
            pDrv.a[i-1]= i * (poly.a[i]);
        }
    return pDrv;
}

void affichePoly(polynome poly)
{
	int i;
    int help = 0 ; //aide dans l'affichage du signe
    for(i=0;i<=poly.n;i++)
    {
        if(poly.a[i]!=0 )
        {
            if(poly.a[i]>0 && help == 0 || poly.a[i]<0)
            {
                 printf("%.2f * x^%d",poly.a[i],i);
                 help = 1;
            }
            else
                 if(poly.a[i]>0)
                 printf(" + %.2f * x^%d ",poly.a[i],i);
        }
    }
}

float evaluer(polynome poly, float x){
	float img=0;
	int i;
	for(i=poly.n;i>=0;i--)
		img=img*x+poly.a[i];
	return img;
}

int main()
{
    polynome poly1;
    polynome poly2;

    printf("la saisie du polynome 1 \n\n");
    poly1=saisirPoly();
    printf("\n\nla saisie du polynome 2 \n\n");
    poly2=saisirPoly();

    printf("\n\nl'affichage du polynome 1 \n\n");
    affichePoly(poly1);
    printf("\n\nl'affichage du polynome 2 \n\n");
    affichePoly(poly2);

    printf("\n\npoly1(%.2f)=%.2f\n\n",1.94,evaluer(poly1,1.94));

    polynome polySomme = sommePoly(poly1,poly2);
    printf("\n\npoly1 + poly2 : \n");
    affichePoly(polySomme);

    printf("\n\nchangement de signe du poly1 : \n");
    changeSigne(&poly1);
    affichePoly(poly1);

    polynome polySous = soustractionPoly(poly1,poly2);
    printf("\n\npoly1 - poly2 : \n");
    affichePoly(polySous);
    printf("\n\n");

    comparePoly(poly1,poly2);

    printf("\n\nchangement de signe du poly1 : \n");
    changeSigne(&poly1);
    affichePoly(poly1);

    printf("\n\nderivee de poly1\n\n");
    polynome polyDeriv = derivPoly(poly1);
    affichePoly(polyDeriv);
    printf("\n\n");
    return 0;
}
