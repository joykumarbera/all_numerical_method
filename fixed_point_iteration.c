#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define theta 0.00001 // for accuracy checking

// function decleration
float fun(float x, float a); 
float myFun(float x, float a);

int usr_input;

int main(int argc, char const *argv[])
{
    int flag=0, i=0;
    float x_0, a, temp;

    printf("\n\n\t\t\t----::fixed point iteration::----\n\n\n");

    again:      
    printf("\nenter a: ");
    scanf("%f",&a);
    printf("enter frist point for iteration: ");
    scanf("%f",&x_0);
    
    while(flag == 0)
    {
       
        temp = myFun(x_0,a);
        printf("\n no:%d:: \tx_n:%0.9f\tx_n+1:%0.9f",i,x_0,temp);

        if(fabs(fun(temp,a))<theta)
        {
            printf("\n\n\n final ans: %0.5f",temp);
            printf("\n\n function value: %f",fun(temp,a));
            flag = 1; 
        }
        else
        {
            x_0 = temp;
            i++;
        }
    }

    printf("\n\nfor coninue press 1 | for exit press 0: ");
    scanf("%d",&usr_input);
    
    if( usr_input == 1)
    {
        system("cls");
        goto again; // for continue the application
    }
    else
    {
        exit(0);
    } // for close the application
    
    return 0;
}

// function defination's

float myFun(float x, float a) {
    return pow((a-cos(a*x))/2,1/(a+x));
}
float fun(float x, float a) {
    return 2*pow(x,a+x)+cos(a*x)-a;
}