#include<stdio.h>
#include "header/numerical.h"

int main()
{
	
	 float x0, x1, x2, f0, f1, f2, e;
	 int step = 1;
	 printf("\nEnter two initial guesses:\n");
	 scanf("%f%f", &x0, &x1);
	 printf("Enter tolerable error:\n");
	 scanf("%f", &e);
	 x2= RegularFalsi(x0,x1,e);
	 printf("\nRoot is: %f", x2);
	 return 0;
}