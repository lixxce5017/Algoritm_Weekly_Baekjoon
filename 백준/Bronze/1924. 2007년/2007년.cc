#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
#define MAX 500004
//지금까지 달의 요일을 모두 더한 상태에서 7로 나눴어야함
//문제에서 31일 달들과 2월은 28 , 30의 달들을 모두 명시해줬음
int daysOfMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
char arr[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int main()
{
	int x, y;
	cin >> x >> y;
	int temp=y;
	for (int i = 1; i < x; i++)
	{
		temp += daysOfMonth[i];
	}
	cout << arr[temp % 7];
	return 0;
}