#include<stdio.h> // fichier entete (header) texte qui contient les infos utiles 
				  //pour le compilateur sur les fonctions E/S

/* codage C de la recherche dichotomique 
int *l = int* l => l est l'adresse d'un entier notamment le 1er entier de la liste
g et d délimitent le domaine de recherche
x entier à rechercher

*/
static int rechercherBin(int *l,int g,int d,int x){
	if(d<g) return -1;
	int m=(g+d)/2; // division entiere, car g+d est entier et 2 est entier
	if(l[m]==x) return m;
	if(l[m]>x)return rechercherBin(l,g,m-1,x);
	return rechercherBin(l,m+1,d,x);
}

int rechercher(int *l,int n,int x){
	return rechercherBin(l,0,n-1,x);
}


int main(){
	int T[]={3,7,8,11,15,20,20,20,100,110,111,200,201};// 11 elts
	int n=13;
	int x;
	printf("entrez un entier : ");
	scanf("%d",&x); // %d est signe de codage utilisé pour les entiers de type int
	// &x se lit adresse de x 
	int p=rechercher(T,n,x);
	if(p==-1)
		printf("%d n'est dans la liste\n",x);
	else
		printf("%d apparient a la liste elle est a position %d\n",x,p);
	
	return 0; // 0 est synonyme de l'aboutissement normal de l'execution	
}
