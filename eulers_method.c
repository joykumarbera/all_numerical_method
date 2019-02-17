// Eulers method 
/*
    by Joy Kumar bera
*/

#include <stdio.h>
#include <math.h>
float fun(float , float);
float nodes(float , int , float);
int main(int argc, char const *argv[])
{
    float x_0, y_0, x, h;
    printf("\t\t\t---::Eulers method::---");
    printf("\nenter intial x_0: ");
    scanf("%f",&x_0);
    printf("enter initail y_0: ");
    scanf("%f",&y_0);
    printf("\nenter final value of x: ");
    scanf("%f",&x);
    printf("\nenter h: ");
    scanf("%f",&h);
    int i=0;
    do
    {
        float temp;
        temp = y_0 + h*fun(nodes(x_0,i,h),y_0);
        printf("\ny(%0.2f):: %0.3f",nodes(x_0,i,h),temp);
        y_0 = temp;
        i++;
    }while( nodes(x_0,i,h) != x );

    return 0;
}
float fun(float x, float y) {  
    return x*y;
}
float nodes(float x_0, int i, float h) {
    float x;
    x = x_0 + (i*h);    
    return x;
}