#include<stdio.h>
#include "header/numerical.h"

int main()
{
    float a,b,c,d,e;
    int count=1,n;
    printf("\n\nEnter the values of a and b:\n"); //(a,b) must contain the solution.
    scanf("%f%f",&a,&b);
    printf("Enter the values of allowed error and maximun number of iterations:\n");
    scanf("%f %d",&e,&n);
    c = secant(a,b,e,n);
    printf("\n The required solution is %f\n",c);
    return 0;
    
}