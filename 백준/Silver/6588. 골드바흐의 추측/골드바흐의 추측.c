#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define arrNum 1000000
int main(void)
{
 
int Number,arr[arrNum] = {0};
  int n;

arr[0] = 1 ,arr[1] = 1;
    
  for(int i=2; i<=sqrt(arrNum); i++)
    {
      if(arr[i]==1) continue;
      for(int j=2; i*j<=arrNum;j++)
        {
          arr[i*j]=1;
        }
    }

while(1){
 int n=0;
  int l=0;
  bool find=false;
  scanf("%d",&n);
  if(n==0)
  {
    break;
  }
  for(int j=2; j<=n/2; j++)
    { 
      if(arr[j] != 1 && arr[n-j] != 1)
      {
        l=j;
        find = true;
        break;
      }
    }
      if(find ==true)
      {
          printf("%d = %d + %d\n", n, l, n-l);
      }
      else
        printf("Goldbach's conjecture is wrong.");
        
  }
  return 0;
  }
