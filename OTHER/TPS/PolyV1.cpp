// manipulation des polynomes
#include<stdio.h>
#include<stdlib.h>
// structure de données
//sol1 => tableau surdimensionné
#define  DMAX 10000 
// condition 0<= n <=DMAX
typedef int entier;
typedef double reel;
struct poly_T{
	entier n; // champs|propriétés\attributs
	reel a[DMAX+1];
};

typedef struct poly_T  poly_t;

//opérations spus forme de fontions

poly_t saisir(){
	poly_t p;
	int i;
	int d;
	p.n=0;
	printf("saisie des cofficients non nuls et leurs degrés\nPour arreter, il suffit de saisir un degre negatif\n"); 
	for(i=0;i<=DMAX;i++)p.a[i]=0;
	do{
		printf("degre du monome suivant : ");
		scanf("%d",&d);
		if(d>=0){
			printf("coef a%d = ",d);
			scanf("%lf",&p.a[d]);
			if(d>p.n) p.n=d;	
		}
	}while(d>=0);
	return p;	
}


void afficher(poly_t p){
	int i;
	printf("{Polynome : \n");
	printf("\tDegre : %d\n",p.n);
	printf("\tCoeffs : [%.2f",p.a[0]);
	for(i=1;i<=p.n;i++)
		if(p.a[i])printf("%.2f",p.a[i]);
	printf("]\n}\n");
}


double evaluer(poly_t p, double x){
	double y=0;
	int i;
	for(i=p.n;i>=0;i--)
		y=y*x+p.a[i];	
	return y;	
}

int main(){
	system("cls");
	poly_t q;
	q=saisir();
	afficher(q);
	double x=1;
	double y=evaluer(q,x);
	printf("q(%.2f)=%e\n",x,y);
	system("pause");
}
