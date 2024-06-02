#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
using namespace std;
#define MAX 500004
//그냥 파우 때리면 무저꿘 int 형 넘어감
//string으로 빼는 것도 있지만 pow가 소숫점까지 끌고와서 구현 실패
//결국 마지막 자리만 계속 곱해주는다는 것은 마지막 자리만 보면 되기 때문에

int main()
{
	int t;
	cin >> t;
	while (t)
	{
		int a, b;
		cin >> a >> b;
		int temp1;
		temp1 = a;
		for (int i = 1; i < b; i++)
		{
			temp1 =temp1*a % 10;
		}
		//10까지는 출력해야해서 예외처리
		if (temp1 % 10 == 0)
		{
			cout << 10<<"\n";
		}
		else
		cout << temp1 % 10<<"\n";


		t--;
	}
	return 0;
}