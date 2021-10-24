#include <stdio.h>
#include <stdlib.h>

#define  DegM 10 //la degrée max

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

void affichePoly(polynome poly)
{
    int help = 0, i; //aide dans l'affichage du signe
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

float Eval_iterative(polynome poly,float x)
{
	float img=0;
	int i;
	for(i=poly.n;i>=0;i--)
		{
  			img=img*x+poly.a[i];
  			printf("\nimg = %.2f\n",img);

		}
	return img;	
}

int main() {
	polynome p1 = saisirPoly();
	affichePoly(p1);
	printf("\nP1(5) = %.2f",Eval_iterative(p1,5));
	return 0;
}
