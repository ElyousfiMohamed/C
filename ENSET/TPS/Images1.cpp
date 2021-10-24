/* Manip img monchrome
	1) creation
	2) saisir\initialiser une img
	3) affichage (caracteristique)
	4) claculs (miroirV,mirroirH,...), 
	determiner la couleur dominante, 
	modifier une couleur, ...)
*/
#include<stdio.h>
//creation image de taille maximale NmaxxNmax pixels
#define Nmax 1000 //img 1000x1000 pxls

struct imgT{
	int L,H,R;
	unsigned char pxls[Nmax][Nmax];
	int nl,nc;
};

typedef struct imgT imgt;

imgt img1,img2,*p,*q;

void saisirImg(imgt *p){ //transmission d'une petite adresse donc légère
	//saisair img
	do{
		printf("Longueur : ");
		scanf("%d",&p->L);
		printf("Hauteur : ");
		scanf("%d",&p->H);
		printf("Resolution : ");
		scanf("%d",&p->R);
		p->nl=p->L*p->R;
		p->nc=p->H*p->R;
	}while(p->nc>Nmax||p->nl>Nmax);
	for(int i=0;i<p->nl;i++)
		for(int j=0;j<p->nc;j++){
			printf("pxls[%d][%d]=",i,j);
			scanf("%u",&p->pxls[i][j]);
		}
}

void afficherImg(const imgt *p){
	printf("Image : {\n\tLongueur : %d\n\tHauteur : %d\n\tResolution : %d\n"
	,p->L,p->H,p->R);
	printf("\t[\n");
	for(int i=0;i<p->nl;i++){
		printf("\t\t");
		for(int j=0;j<p->nc;j++)
			printf("%4d",p->pxls[i][j]);
		printf("\n");
	}
	printf("\t]\n}");
}

int main(){
	//saisie
	saisirImg(&img1);
	saisirImg(&img2);	
	//Calculs
	//...
	//affichage
	afficherImg(&img1);
	afficherImg(&img2);	
	return 0;
}

