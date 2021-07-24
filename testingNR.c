#include <stdio.h>
#include "header/numerical.h"
int main()
{
    int itr, maxmitr;
    float h, x0, x1, allerr;
    printf("\nEnter x0, allowed error and maximum iterations\n");
    scanf("%f %f %d", &x0, &allerr, &maxmitr);
    x1 = NewtonRaphson(x0,allerr,maxmitr);
    printf("Root = %8.6f\n",  x1);
    return 0;
    
}