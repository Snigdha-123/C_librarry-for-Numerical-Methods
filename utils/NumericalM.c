//function for Newton Raphson
#include "extras.h"
#include<stdio.h>
#include<math.h>
float NewtonRaphson(float x0,float allerr,int maxmitr)
{
    int itr;
    float x1,h;
        for (itr=1; itr<=maxmitr; itr++)
    {
        h=f(x0)/df(x0);
        x1=x0-h;
       // printf(" At Iteration no. %3d, x = %9.6f\n", itr, x1);
        if (fabs(h) < allerr)
        {
            return x1;
        }
        x0=x1;
    }
    printf(" The required solution does not converge or iterations are insufficient\n");
    return 1;
}

//Secant Method
float secant(float a ,float b,float e ,int n)
{
    float c;
    int count =1;
    do
    {
        if(f1(a)==f1(b))
        {
            printf("\nSolution cannot be found as the values of a and b are same.\n");
        return 0;
        }
        c=(a*f1(b)-b*f1(a))/(f1(b)-f1(a));
        a=b;
        b=c;
        //printf("Iteration No-%d    x=%f\n",count,c);
        count++;
        if(count==n)
        {
        break;
        }
    } while(fabs(f1(c))>e);
    return c;
    
}

//Regular-falsi
float RegularFalsi(float x0,float x1,float e)
{
    int step=1;
    float f0,f1,x2,f2;
    f0 = f(x0);
	 f1 = f(x1);
	 if( f0*f1 > 0.0)
	 {
		  printf("Incorrect Initial Guesses.\n");
	return 0;
	 }
	 /* Implementing Regula Falsi or False Position Method */
	 //printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
	 do
	 {
		  x2 = x0 - (x0-x1) * f0/(f0-f1);
		  f2 = f(x2);
		  //printf("%d\t\t%f\t%f\t%f\t%f\n",step, x0, x1, x2, f2);
		
		  if(f0*f2 < 0)
		  {
			   x1 = x2;
			   f1 = f2;
		  }
		  else
		  {
			   x0 = x2;
			   f0 = f2;
		  }
		  step = step + 1;
	
	 }while(fabs(f2)>e);
	 return x2;
	  
}

//Simpson Method
float simpson(float x0,float xn,float h)
{
    int n,i;
    float so,se,ans,x[20],y[20],a;
     n=(xn-x0)/h;
    if(n%2==1)
    {
        n=n+1;
    }
    h=(xn-x0)/n;
     for(i=0; i<=n; i++)
    {
        x[i]=x0+i*h;
        a =1/(1+(x[i]));
        y[i]=a;
        //printf("\n%f\n",y[i]);
    }
    so=0;
    se=0;
    for(i=1; i<n; i++)
    {
        if(i%2==1)
        {
            so=so+y[i];
        }
        else
        {
            se=se+y[i];
        }
    }
    ans=h/3*(y[0]+y[n]+4*so+2*se);
    return ans;
}
//trapezoidal
float trapezoidal(float x0,float xn,float h)
{
    int n,i;
    float so,se,ans,x[20],y[20],a;
     n=(xn-x0)/h;
    if(n%2==1)
    {
        n=n+1;
    }
    h=(xn-x0)/n;
     for(i=0; i<=n; i++)
    {
        x[i]=x0+i*h;
        a =1/(1+(x[i]*x[i]));
        y[i]=a;
        printf("\n%f\n",y[i]);
    }
    so=0;
    se=0;
    for(i=1; i<n; i++)
    {
        if(i%2==1)
        {
            so=so+y[i];
        }
        else
        {
            se=se+y[i];
        }
    }
    ans=h/3*(y[0]+y[n]+4*so+2*se);
    return ans;
}
//Newton -Forward
int newtonforwad(float ax[],float ay[],float x,int n)
{
    int ORDER =4,MAXN=100;
    int h,i,j,p,yp,nr=1.0,dr=1.0,k;
    int diff[MAXN +1][ORDER+1];
    h=ax[1]-ax[0];
    //now making the difference table
    //calculating the 1st order of differences
    for (i=0;i<=n-1;i++)
        diff[i][1] = ay[i+1]-ay[i];
        //now calculating the second and higher order differences
    for (j=2;j<=ORDER;j++)
        for(i=0;i<=n-j;i++)
        diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
         i=0;
    while (!(ax[i]>x))
        i++;
        i--;
    p = (x-ax[i])/h;
    yp = ay[i];
    for (k=1;k<=ORDER;k++)
    {
        nr *=p-k+1;
        dr *=k;
        yp +=(nr/dr)*diff[i][k];
    }
    return yp;
    
}
//weddle method
float WeedleRule(float a, float b)
{
    // Find step size h
    double h = (b - a) / 6;
  
    // To store the final sum
    float sum = 0;
  
    // Find sum using Weedle's Formula
    sum = sum + (((3 * h) / 10) * (y(a)
                                   + y(a + 2 * h)
                                   + 5 * y(a + h)
                                   + 6 * y(a + 3 * h)
                                   + y(a + 4 * h)
                                   + 5 * y(a + 5 * h)
                                   + y(a + 6 * h)));
  
    // Return the final sum
    return sum;
}