#include <stdio.h>

int main(void)
{  
  int arr[100000] ={0,};
 
  
    int n;

    //생성자가 있는지 없는지 검사.
  for(int i=1; i<=10000; i++)
    {
      int sum=0;
      int n=i;
    int b=0,c=0,d=0,e=0;
     b = n / 1000;
    c = (n % 1000)/100;
    d = (n % 100)/10;
    e = (n % 10)/1;
      sum=n+b+c+d+e;
    arr[sum]=1;
    }
   for(int i=1;i<=10000; i++)
     {
       if(arr[i]==0)
       {
         printf("%d\n",i);
       }
     }
    
  
}