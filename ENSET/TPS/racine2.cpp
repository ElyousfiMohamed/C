	#include<stdio.h>
	#include<math.h> // pour la fct fabs
	#include<time.h>
	
	void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 100 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 
	//précondition : y>=0
 	static double calculerRacine(double y, double g, double d ){
 		const double eps= 1.e-6;
		if (y==0 || y==1) return y;
		double m=(g+d)/2;
		printf("milieu m = %f\ndomain[%f  %f]\n",m,g,d);
		delay(1);
		if(fabs(m*m-y)<=eps) return m;
		if(m*m>y) return calculerRacine(y,g,m);// rech dans le domaine gauche
		return calculerRacine(y,m,d); 	
	}
	
	double getRacine(double y){
		if(y<1)
			return calculerRacine(y,y,1);
		return calculerRacine(y,1,y);		
	}
	
	int main(){
		double a,x;
		do{
			printf("Entrez un reel positif : ");
			scanf("%lf",&a);
		}while(a<0);
		x=getRacine(a);
		printf("la racine de %f est %.8f\n",a,x);
		return 0; // execution normale
	}
