/* 
    
    trapezydel rule

*/

// coded by Joy kumar bera using heap memory


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double func(double, double);

void main(int argc, char const *argv[])
{
  
    double u_lim, l_lim, b, h, r, n, sum=0, temp;
    printf("enter number of ordinates: ");
    scanf("%lf",&n);
    printf("\nenter upper limit: ");
    scanf("%lf",&u_lim);
    printf("\nenter lower limit: ");
    scanf("%lf",&l_lim);
    printf("\nenter R: ");
    scanf("%lf",&r);

    b = 1.0+((r+1)/20);
    h = (u_lim-l_lim)/(n-1);
    temp = h;

    double* ptr =(double*)malloc(n*sizeof(double));

    for(int i=0; i<n; i++)
    {
        *(ptr+i) = func(l_lim,b);
      //  printf("f(%d): %0.9lf\n",i,*(ptr+i));

        if(i==0 || i==n-1)
        {
            *(ptr+i) = *(ptr+i);
        }
        else
        {
            *(ptr+i) = 2* *(ptr+i);
        }
        sum = sum+*(ptr+i);

        l_lim = l_lim + h; 
    }
    printf("\ntotal sum: %0.9lf",sum);
    printf("\nans: %0.9lf",(temp/2)*sum);
}
double func(double x, double b) {
    return (1+pow(x,2)*log(1+b*pow(x,2))) / (1.1+b*x+pow(x,2));
}