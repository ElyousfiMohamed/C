#include<stdio.h>
/* 
programmer le tri par fusion
	1) Division
	2) TriFusion
	3) Fusion
*/


const int N=10; // crée une case mémoire N de valeur fixe
int T[N]={2,18,27,35,43,50,65,113,120,200}; // le tableau des entiers à trier

//les fonctions
//déclarations ==> fixe le quoi de la fonction
void triFusion(int [],int );
void diviser(int [],int [],int [],int );
void fusionner(int [],int [],int [],int );
void afficher(int*,int);

//définitions ==> fixe le comment de lafonction,
void triFusion(int t[],int n){
	int tg[N/2],td[N-N/2];
	if(n>1){
		diviser(t,tg,td,n); //appel à la fonction diviser
		triFusion(tg,n/2); //appel recursif à la fonction tri
		triFusion(td,n-n/2);
		fusionner(t,tg,td,n);
	}	
}

void diviser(int t[],int tg[],int td[],int n){
	int m1=n/2,i,m2=n-m1;
	for(i=0;i<m1;i++){
		tg[i]=t[i];
		td[i]=t[m1+i];
	}
	if(m2>m1)td[m2-1]=t[n-1];
}

void fusionner(int t[],int tg[],int td[],int n){
	int m1=n/2,m2=n-m1,i,j,k;
	i=j=k=0;
	while(i<m1 && j<m2){
		if(tg[i]<td[j]){
			t[k]=tg[i];
			i++;k++;
		}
		else{
			t[k]=td[j];
			j++;k++;			
		}
	}
	// traitement du reste qui est soit dans tg ou dans td
	for(;i<m1;i++,k++)
		t[k]=tg[i];
	for(;j<m2;j++,k++)
		t[k]=td[j];			
}

void afficher(int t[],int n)
{
	printf("t={");
	for(int i=0;i<n;i++)
		printf("%4d",t[i]);
	printf("}\n");
}
int main(){
	afficher(T,N);
	triFusion(T,N);
	afficher(T,N);
	return 0;
}
