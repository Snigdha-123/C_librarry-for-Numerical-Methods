#include<stdio.h>
#include "header/numerical.h"

int main()
{
    int MAXN = 100;
    int ORDER =4;
    float ax[MAXN+1], ay [MAXN+1], diff[MAXN+1][ORDER+1], nr=1.0, dr=1.0,x,p,h,yp;
    int n,i,j,k;
    printf("\nEnter the value of n:\n");
    scanf("%d",&n);
    printf("\nEnter the values in form x,y:\n");
    for (i=0;i<=n;i++)
    scanf("%f %f",&ax[i],&ay[i]);
    printf("\nEnter the value of x for which the value of y is wanted: \n");
    scanf("%f",&x);
     yp = newtonforwad(ax,ay,x,n);
    printf("the value of yp is %f",yp);
}