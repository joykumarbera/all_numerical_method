#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double func(double, double);
int usr_inp;
int main(int argc, char const *argv[])
{
    system("color 0a");
    float a_0, b_0, h, r, b, n, a[50], temp;
    double sum=0;

    cal:

    printf("\n\n ----::Weddle's Rule::----");
    printf("\n\n\n enter upper limit: ");
    scanf("%f",&b_0);
    printf("\n enter lower limit: ");
    scanf("%f",&a_0);
    printf("\n enter number of ordinates: ");
    scanf("%f",&n);
    printf("\n enter R: ");
    scanf("%f",&r);

    b=1.1+((1+r)/20);

    h = (b_0-a_0)/(n-1);
    temp = h;


    printf("\n b: %f",b);
    printf("\n h: %f\n\n",h);

    for(int i=0; i<n; i++)
    {
        double temp;
        a[i] = func(a_0,b);
        temp = a[i];
        printf("\n f(x_%d): %lf",i,a[i]);
        if(i==0 || i == n-1)
        {
            a[i] = a[i];
        }
        else if(i%6==0)
        {
            a[i] = 2*a[i];
        }
        else if(i%3==0)
        {
            a[i] = 6*a[i];
        }
        else if(i%2 == 0)
        {
            a[i] = a[i];
        }
        else
        {
            a[i] = 5*a[i];
        }
        printf("\tc: %0.1lf",a[i]/temp);
        printf("\tc_n_y_n: %lf",a[i]);
        sum=sum+a[i];
        a_0=a_0+h;

    }
   
    printf("\n\n total sum: %lf",sum);
    printf("\n\n ans: %lf",(3*temp/10)*sum);
    printf("\n\n press 0 for continue | press 1 for exit: ");
    scanf("%d",&usr_inp);
    if(usr_inp == 0)
    {
        system("cls");
        goto cal;
    }
    else
    exit(EXIT_SUCCESS);

    
    return 0;
}
double func(double x, double b)
{
    return ( (1+x+pow(x,2)*cosh(b*x)) / (1.2+b*x+pow(x,2)) );
}