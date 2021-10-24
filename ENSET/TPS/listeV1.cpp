#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


//gestion d'une liste d'entiers simplement chainée

typedef struct listT{
	int x;
	struct listT *s; //suivant
}listt;

int main(){
	listt *t=NULL; //tete de la liste vide
	listt *q=NULL; //queue de la liste
	listt *p;
	int lg=0; //longueur de la liste
	int oper;
	do{
		system("cls");
		puts("Ajout en queue       ------->   1");
		puts("Afficher la liste    ------->   2");
		puts("Quitter              ------->   8");
		
		scanf("%d",&oper);
		switch(oper){
			case 1: //creation d'un nouveau en queue de liste
				p=(listt *)malloc(sizeof(listt));
				p->s=NULL;
				if(lg)//la liste contient au moins un noeud	
					q->s=p;
				else
					t=p;
				q=p;
				lg++;
				//scan de la valeur de x pointé par p
				printf("entrez un entier : ");
				scanf("%d",&p->x);
				break;
			case 2://afficher la liste de la tete vers la queue
				system("cls"); //nettoyer l'écran
				p=t;
				printf("Longueur de la liste = %d\n",lg);
				while(p){
					printf("%d-->",p->x);
					p=p->s;
				}	
				puts("");
				system("pause");							
				break;
			case 8 :
				system("pause");
				exit(1);
		}
	}while(1);
	return 0;
}
