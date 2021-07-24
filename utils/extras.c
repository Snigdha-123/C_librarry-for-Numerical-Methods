#include<math.h>
//newton Raphson Method,Regular-Falsi
float f(float x)
{
    return x*log10(x) - 1.2;
}
float df (float x)
{
    return log10(x) + 0.43429;
}
//Secant Mathod
float f1(float x)
{
    return(x*x*x-4); // f(x)= x^3-4
}
//weddle method
float y(float x)
{
    float num = 1;
    float denom = 1.0 + x * x;
  
    return num / denom;
}
