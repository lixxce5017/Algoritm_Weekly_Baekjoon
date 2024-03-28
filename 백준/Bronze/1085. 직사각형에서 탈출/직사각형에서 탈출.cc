#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
#include<tuple>
#include<queue>;
using namespace std;

int main()
{	//R이 34, 23 green, blue 18
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	//기본적으로 얘네 거리보다
	int x = min(x1, abs(x1 - x2));
	int y = min(y1, abs(y1 - y2));
	cout << min(x,y);
	
}