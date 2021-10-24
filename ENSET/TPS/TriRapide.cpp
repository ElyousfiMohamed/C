#include<stdio.h>
 

void permuter(short t[] ,int i,int j){ //int t[] => tableau non contraint
	short x=t[i];
	t[i]=t[j];
	t[j]=x;
}
int getMax(short *t, int g, int d){
	short max=t[g];
	for(int i=g+1;i<=d;i++) max=t[i]>max?t[i]:max;
	return max+1;
}

void afficher(short *t,int g,int d){
	printf("[");
	for(int i=g;i<=d;i++)
		printf("%4hd, ",t[i]);
	printf("%4hd]\n\n\n",t[d]);
}

int partitionner(short *t,int g, int d){
	short pivot=t[g]; // il faut optimiser le choix du pivot
	int i=g,j=d;
	while(i<j){
		do{
			i++;	
		}while(t[i]<=pivot ); // attention ajouter à la fin une valeur 					 //fictive plus grande que t[i] i=g ..d-1
							 //si non boucle infinie pour certains cas
		do{
			j--;
		}while(t[j]>pivot);
		if(i<j)	permuter(t,i,j);
		//afficher(t,g,d);
	}
	permuter(t,g,j); // deplacement du pivot
	return j;	
}

void trier(short *t,int g ,int d){
	if(g<d){
		int j=partitionner(t,g,d);
		//printf("j=%d\n",j);
		//afficher(t,g,d);
		trier(t,g,j); // tri de la partition gauche
		trier(t,j+1,d);
	}
}
int main(){
	const int n=8;
	short t[n+1]={7,11,5,1,20,13,9,10};
	t[n]=getMax(t,0,n-1);
	//printf("max=%d")
	afficher(t,0,n-1);
	trier(t,0,n);
	//partitionner(t,0,8);
	afficher(t,0,n-1);
}
