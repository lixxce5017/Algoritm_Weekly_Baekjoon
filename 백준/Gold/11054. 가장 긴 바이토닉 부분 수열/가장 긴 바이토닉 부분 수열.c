#include <stdio.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>
int LIS[1000]= {0};
int n;
int str[1000];
int LIS2[1000]={0};
int maxx(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else {
		return b;
	}
}
int main(void)
{
	int i, j;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &str[i]);
	}


	//앞에서 부터 최장 증가
	for (i = 0; i < n; i++)
	{
		LIS[i] = 1;
		for (j = 0; j <= i; j++)
		{
			if (str[j] < str[i] && LIS[i] <LIS[j]+1)
			{
				LIS[i]++;
			}

		}
	}
	//뒤에서 부터 최장 감소
	for (i = n-1; i>=0; i--)
	{
		LIS2[i] = 1;
		for (j = n-1; j >= i; j--)
		{
			if (str[j] < str[i] &&LIS2[i] < LIS2[j]+1)
			{
				LIS2[i]++;
			}
		}
	}
	int max = 0;
	//합치기 -1
	for (int i = 0; i < n; i++)
	{
		if (max < LIS[i] + LIS2[i])
			max = LIS[i] + LIS2[i];
	}
	max = max - 1;
	printf("%d", max);
}
