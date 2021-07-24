#include<stdio.h>

#include "header/numerical.h"

int main()
{
    // lower limit and upper limit
    float a ,b;
    printf("Enter the lower and upper limit");
    scanf("%f %f",&a,&b);
  
    // Function Call
    printf("f(x) = %f", WeedleRule(a, b));
    return 0;
}