#include <stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main(void) {

	int county[101] = { 0, };

	int student[101] = { 0, };

	int score[101] = { 0, };

	int n;
	cin >> n;
	int goldfalg = 0;
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> county[i] >> student[i] >> score[i];
		if (max < score[i])
		{
			goldfalg = i;
			max = score[i];
		}
	}
	max = 0;
	int silverflag = 0;
	for (int i = 1; i <= n; i++)
	{
	
		if (max < score[i] && goldfalg!=i)
		{
			silverflag = i;
			max = score[i];
		}
	}
	int therdflg = 0;
	max = 0;
	int no = 0;
	if (county[goldfalg] == county[silverflag])
	{
		 no = county[goldfalg];
	}
	for (int i = 1; i <= n; i++)
	{
		if (max < score[i]&&i!=goldfalg&& i!=silverflag &&county[i]!= no)
		{
			{
				therdflg = i;
				max = score[i];
			}
		}
	}
	cout << county[goldfalg] <<" "<< student[goldfalg] << "\n";
	cout << county[silverflag] <<" " << student[silverflag] << "\n";
	cout << county[therdflg] <<" "<< student[therdflg] << "\n";
}
