#include<stdio.h>
#include<stdlib.h>
#include <string.h>


int maxx(int a, int b);



int LCS[4002][4002];
char s[4002];
char s2[4002];
int max_len = 0;


int main()
{
	scanf("%s", s, sizeof(s));
	scanf("%s", s2, sizeof(s2));
	for (int i = 0; i < strlen(s); i++)
	{
		for(int j=0; j<strlen(s2); j++)
		if (s[i] == s2[j]) {
			{
				if (i == 0 || j == 0)
				{
					LCS[i][j] = 1;
				}
				else
				{
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
					max_len = maxx(max_len, LCS[i][j]);
				}
			}
		}
	}
		
	printf("%d", max_len);

}

int maxx(int a, int b) {
	if (a < b) {
		return b;
	}
	else {
		return a;
	}
}
