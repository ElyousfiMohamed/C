#include <stdio.h>
#include <stdlib.h>

#define  DegM 1000 //la degrée max

struct polynomeT{
    int n; //degréé de polynome
    double a[DegM+1];
};

typedef struct polynomeT polynome;

polynome saisirPoly()
{
    int deg;
    polynome poly;
    poly.n=0; // on suppose que la degree initiale de polynome est 0

    //en initialise les coeficients a 0, et on demande au utilisateur a saisir les coeficients non nulls
    for(int i=0;i<DegM+1;i++)
        poly.a[i] = 0;

    do{
        printf("veuillez donnez la degre du coefficient a saisir(1000 au max)\n(degree negatif pour s'arreter)\n");
        printf("degree : ");scanf("%d",&deg);
        if(deg>=0 && deg<=DegM)
        {
            printf("a%d = ",deg);scanf("%lf",&poly.a[deg]);
            if(deg>poly.n)
                poly.n = deg; //m-a-j de degree de polynome
        }
    }while(deg>=0 && deg<=DegM);
    return poly;
}

polynome derivPoly(polynome poly)
{
    polynome pDrv;
    pDrv.n = poly.n-1;
     for(int i=1;i<=poly.n;i++)
        {
            pDrv.a[i-1]= i * (poly.a[i]);
        }
    return pDrv;
}

void affichePoly(polynome poly)
{
    int help = 0 ; //aide dans l'affichage du signe
    for(int i=0;i<=poly.n;i++)
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

double evaluer(polynome poly, double x){
	double img=0;
	for(int i=poly.n;i>=0;i--)
		img=img*x+poly.a[i];
	return img;
}

void calculRacine(polynome poly,polynome drvPoly,double x0,int k)
{
    printf("k = 0      x0 = %lf      p(x0) = %lf\n",x0,evaluer(poly,x0));
    double aide = x0;
    for(int i=1;i<=k;i++)
    {
         printf("k = %d      x%d = %lf      p(x0) = %lf\n",i,i,aide=x0-(double)(evaluer(poly,aide)/evaluer(drvPoly,aide)),evaluer(poly,aide));
         x0=aide;
    }
}

int main()
{
    double r;
    int k;
    polynome poly1;
    printf("la saisie du polynome 1 \n\n");
    poly1=saisirPoly();

    printf("\n\nl'affichage du polynome 1 \n\n");
    affichePoly(poly1);

    printf("\n\nderivee de poly1\n\n");
    polynome poly1Deriv = derivPoly(poly1);
    affichePoly(poly1Deriv);
    printf("\n\n");

    printf("donnez 'r' l'estimation initiale de la racine\n");
    scanf("%lf",&r);

    printf("donnez 'k' le nombre d'iterations\n");
    scanf("%d",&k);

    calculRacine(poly1,poly1Deriv,r,k);
    return 0;
}
