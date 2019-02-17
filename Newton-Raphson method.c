#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// function decleration
double func(double, double);
double dev_func(double, double);

/* main program stars here */

int main(int argc, char const *argv[])
{
    int user_choice, i;
    double x, h, x_n_1, p,r;

    again: // for continue calculation again
    i=0;
    system("color 0b");
//system("color 0a");
    printf("\n\n\n\t\t\t----::Newton-Raphson Method(simple root)::----\n\n");
    printf("\nenter initial guess: ");
    scanf("%lf",&x);
    printf("\nenter R: ");
    scanf("%lf",&r);
    p =  1+(r/10);
    printf("\np: %0.2lf\n",p); 

    cal:
    h = -(func(x,p)/dev_func(x,p));
    x_n_1 = x + h;
    
    if(fabs(x_n_1-x) < 0.0000000001 )
    goto ans;

    else
    {   
        printf("\nno. %d | x:%0.9lf | f(x): %0.9lf | f`(x): %0.9lf | h: %0.9lf | x_n_1: %0.9lf ",i,x,func(x,p),dev_func(x,p),h, x_n_1);
        x = x_n_1;
        i++;
        goto cal;
    }
    ans: 
    printf("\n\nans: %0.9lf",x_n_1);
    system("color 0a");
   // system("color 0b");
    printf("\n\n\t\t\t\tThank You...");

    printf("\n\n\npress 1 to couinue | press 0 to exit: ");
    scanf("%d",&user_choice);
    if(user_choice == 1)
    {
        system("cls");
        goto again;
    }
    else
    exit(0);
    
    return 0;
}
double func(double x, double p)
{
    return pow(x,2)*tanh(x) - pow(exp(1),p*sin(x)) - 3;
}
double dev_func(double x, double p)
{
    return 2*x*tanh(x) + pow(x,2)*(1/pow(cosh(x),2)) - p*cos(x)*pow(exp(1),p*sin(x));
}