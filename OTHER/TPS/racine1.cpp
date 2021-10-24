	#include<stdio.h>
	#include<math.h> // pour la fct fabs

 	float calculerRacine(float y, float g, float d ){
 		const float eps= 1.e-6;
		if (y==0 || y==1) return y;
		float m=(g+d)/2;
		if(fabs(m*m-y)<=eps) return m;
		if(m*m>y) return calculerRacine(y,g,m);// rech dans le domaine gauche
		return calculerRacine(y,m,d); 	
	}
	
	int main(){
		float a,x;
		printf("Entrez un reel positif : ");
		scanf("%f",&a);
		if(a<1)
			x=calculerRacine(a,a,1);
		else
			x=calculerRacine(a,1,a);
		printf("la racine de %f est %f\n",a,x);
		return 0; // execution normale
	}
