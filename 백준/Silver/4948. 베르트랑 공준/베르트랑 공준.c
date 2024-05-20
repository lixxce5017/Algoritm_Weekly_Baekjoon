#include <stdio.h>

int main(void)
{
 int arrNum = 246913;
int Number,arr[246913] = {0,};
arr[0] = 1 ,arr[1] = 1;
    
  for(int i=2; i<=arrNum; i++)
    {
      if(arr[i]==1) continue;
      for(int j=2; i*j<=arrNum;j++)
        {
          arr[i*j]=1;
        }
    }
scanf("%d",&Number);
  while(Number!=0)
    {
      int count=0;
  for(int i=Number+1;i<=Number*2; i++)
    {
     if(arr[i] == 0)
            count++;
    }
    printf("%d\n",count);
      scanf("%d",&Number);
      }
  return 0;
}