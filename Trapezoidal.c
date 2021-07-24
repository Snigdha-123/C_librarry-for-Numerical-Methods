#include<stdio.h>
#include "header/numerical.h"

int main()
{
    float x0,xn,h,ans;
    printf("\n Enter values of x0,xn,h:\n");
    scanf("%f%f%f",&x0,&xn,&h);
    ans = trapezoidal(x0,xn,h);
    printf("\nfinal integration is %f",ans);

    //printf("\nrefined value of n and h are:%d  %f\n",n,h);
    //printf("\n Y values \n");
}