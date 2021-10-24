#include <stdio.h>
#include <stdlib.h>

int main()
{
    char _continue='y';
    int count=0;
    float n,min,max,moy;
    printf("nbr : ");
    scanf("%f",&n);
    count++;
    min = n;
    max = n;
    moy = n;
    printf("vous voulez continuez ? Y/N : ");
    scanf("%c",&_continue);
    scanf("%c",&_continue);
    while(_continue == 'y' || _continue == 'Y')
    {
        printf("nbr : ");
        scanf("%f",&n);
        count++;
        if(n > max) max = n;
        if(n < min) min = n;
        moy = moy + n;
        system("cls");
        printf("vous voulez continuez ? Y/N : ");
   		scanf("%c",&_continue);
   		scanf("%c",&_continue);
    }
    system("cls");
    printf("min = %.2f\n",min);
    printf("max = %.2f\n",max);
    printf("moy = %.2f\n",moy/count);
    return 0;
}
