#include <iostream>
using namespace std;
int dp[21][21][21];

int dprecursine(int a, int b, int c);

int main(void)
{
  
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	while (true)
	{
		cin >> a >> b >> c;
		
		if (a == -1 && b == -1 && c == -1)
			break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << dprecursine(a, b, c) << '\n';
	}
}
int dprecursine(int a, int b, int c)
{
  if(a<=0 || b<=0 ||c<=0)
    return 1;
  
  if(a>20 || b>20|| c>20)
    return dprecursine(20,20,20);
  //위의 두 조건은 그대로 같음
	
  if(dp[a][b][c])//이 부분이 핵심 a,b,c가 메모라이제이션 되어 있으면 리턴하여 다시
      return dp[a][b][c];
  
  if(a<b && b<c)
   {		//이부분도 그대로에다가 dp에다가 저장하고 그걸 리턴
     dp[a][b][c] =dprecursine(a,b,c-1)+dprecursine(a,b-1,c-1) -dprecursine(a,b-1,c);
  return  dp[a][b][c];
     
  }
  	//otherwise 부분 그대로 dp
   dp[a][b][c] = dprecursine(a-1, b, c) + dprecursine(a-1, b-1, c) + dprecursine(a-1, b, c-1) - dprecursine(a-1, b-1, c-1);
  return  dp[a][b][c];
}
