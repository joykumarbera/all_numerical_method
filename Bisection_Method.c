// Bisection Method
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define theta 0.00001

double f(double x);
double who_is_big(double , double);
double who_is_small(double, double);
void print_line(void);

int  main(int argc, char const *argv[])
{
    double a, b,a_0, b_0, m;
    int user_input; 
    printf("\t\t\t----:Bisection_Method:----\n");

    enter_innterval:
    printf("\nenter interval: \n ");
    printf("\na: ");
    scanf("%lf",&a);
    printf("\nb: ");
    scanf("%lf",&b);
    if( ( f(a)<0 && f(b)>0 ) )
    {
        goto main_calculation;
    }
    else if ( ( f(a)>0 && f(b)<0 ) )
    {
        goto main_calculation;
    }

    else
    printf("\nno root found in this interval [%0.2lf,%0.2lf] plese try again!\n",a,b);
    goto enter_innterval;

    main_calculation:
    print_line();
    printf("\n");
    printf("no._of_ite\t\ta\t\t\tb\t\t\tm\t\t\tf(m)\n");
    print_line();
    
    a_0 = who_is_small(a,b);
    b_0 = who_is_big(a,b);
    int i=1;
    while(fabs(b_0-a_0) > theta)
    {
        // calulate m
        m = (a_0+b_0)/2;
        printf("\n%d\t\t%lf\t\t%lf\t\t%lf\t\t%lf",i,a_0,b_0,m,f(m));
        if(f(m) == 0)
        {
            break;
        }
        else if ( f(m)*f(a_0) < 0)
        {
            b_0 = m;
        }
        else
        {
            a_0 = m;
        }
        i++;
    }
    printf("\n\n\nfinal ans: %lf",m);
    printf("\n\npress 1 to exit | press 0 to continue: ");
    scanf("%d",&user_input);
    if(user_input == 0)
    goto enter_innterval;
    else
    exit(EXIT_SUCCESS);
   return 0; 
}
double f(double x)
{
    double y;
    y= pow(x,2)-3;
    return y;
}
void print_line(void)
{
    int i=0;
	for(i=1; i<=81; i++)
    printf("-");
}
double who_is_big(double x, double y)
{
    if(x>y)
    return x; // means x is big
    else
    return y; // means y is big

}
double who_is_small(double x, double y)
{
    if(x<y) // means x is small
    return x;
    else
    return y;
}                            
