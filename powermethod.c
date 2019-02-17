// power method
#include <stdio.h>
#include <math.h>
void take_arr_input(float a[][20], int arr_len);
void print_arr(float a[][20], int arr_len);
void print_one_d_arr(float arr[], int arr_len);
float matrix_mul(float a[][20], float  b[], float c[],int arr_len);
float who_is_big(float arr[], int arr_len);
int main(int argc, char const *argv[])
{
   float a[20][20], b[20], c[20];
   int n;
   printf("enter size of matrix: ");
   scanf("%d",&n);
   printf("\nenter matrix element: \n");
   take_arr_input(a,n);
   printf("\nyour matrix is: \n");
   print_arr(a,n);

   // for initial guess
   b[0] = 1;
   for(int i=1; i<n; i++)
   {
      b[i] = 0;
   }


   for(int j=1; j<25; j++)
   {
      float temp;   
      matrix_mul(a,b,c,n);
      temp = who_is_big(c,n);
      printf("\nit: %d\n",j);
      print_one_d_arr(c,n); //  print matix after multiplication with given matrix
      printf("\neigen value: %f\n",temp);
      for(int i=0; i<n; i++)
      {
         c[i] = c[i]/temp;
         b[i] = c[i];
         printf("%f, ",b[i]);
      }
   } 
   return 0;
}
void take_arr_input(float a[][20], int arr_len){
   for(int i=0; i<arr_len; i++)
   {
      for(int j=0; j<arr_len; j++)
      {
         scanf("%f",&a[i][j]);
      }
   }
}
void print_arr(float a[][20], int arr_len){
   for(int i=0; i<arr_len; i++)
   {
      for(int j=0; j<arr_len; j++)
      {
         printf("%0.1f  ",a[i][j]);
      }
      printf("\n");
   }
}
float matrix_mul(float a[][20], float  b[], float c[],int arr_len) {
   for(int i=0; i<arr_len; i++)
   {
      float sum= 0;
      for(int j=0; j<arr_len; j++)
      {
         sum += a[i][j]*b[j];
      }
      c[i] = sum;
   }
}
float who_is_big(float arr[], int arr_len){
   float big = arr[0];
   for(int i=0; i<arr_len; i++)
   {
      if(fabs(arr[i])>fabs(big))
      {
         big = arr[i];
      }
   }
   return big;
}
void print_one_d_arr(float arr[], int arr_len){
   for(int i=0; i<arr_len; i++)
   {
      printf("\n%f",arr[i]);
   }
}