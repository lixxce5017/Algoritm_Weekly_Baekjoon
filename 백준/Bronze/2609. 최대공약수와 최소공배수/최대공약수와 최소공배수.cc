#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include<cstring>
#include<limits.h>
using namespace std;
int gcd(int x, int y)
{
	if (y== 0)
		return x;
	return gcd(y, x % y);
}
int main()
{	
	int a, b;
	cin >> a >> b;
	cout<<gcd(a,b)<<"\n" << (a * b) / gcd(a, b);
	//최소공배수의 성질 최소공배수란 공통된 배수 중 제일 작은것
	//서로소란 최대공약수 제일 큰 공통된 약수가 1인 애들을 말함
	//최소공배수는 최대공약수로 두 수를 곱한 것에 나누면 나온다.
}
