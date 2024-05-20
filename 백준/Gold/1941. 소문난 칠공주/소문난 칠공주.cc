#include <iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

char arr[5][5];
bool chk_team[26];
vector<pair<int,int>>mem_list;
int fx[4] = { 1,0,-1, };
int fy[4] = { 0,-1,0,1 };
bool chk[5][5];
bool chk_connetion[5][5];
int cnt;

//11퍼센트에서 틀린이유 : 그렇게 탐색하면 절때 T자 or 십자 모양의 경우의 수를 못 본다.
//그래서 우리 테트로노미노 할 때도 t 자만 따로 구현하여줬었다.
//그래서 우리는 다시 중첩반복문을 돌려서 4방향 중 제일 작은 값을 제외하는 방법으로 구하였다

//두번째 방법으로는 dfs로만 하면서 추가적으로 백터를 만들어 좌표를 넣고
//거기서 계속 가는 방법으로 t자를 구현 할 수 있다.
//하지만 그건 dpeth가 4일 경우에만 가능하고 dpeth가 7일 경우엔는 총 7dpeth의 T모양이 나오지 않는다
// 이건 printf 찍어보면 어떤 모양으로 나오는지 알 수 있다.


//세번째 그래서 이 문제는 테트로노미노와 또 다른 방법으로 t자를 구현해줘야 한다.

//궁금해 하던 점:s에서 시작하여 총 7개의를 보는데 반대로 오는건 카운트 되는건 어찌 막는가?
//백트래킹 조합 idx에서부터 순서대로 가면서 chk로 막아놔서 역으로 거슬러가는 경우는 나오지 않음
int make_team(int x, int y) {
         // cout << chk[x][y] << " " << chk_connetion[x][y] << "\n";
        int cnt = 1;
        for (int i = 0; i < 4; i++) {
            int nx = fx[i] + x;
            int ny = fy[i] + y;
            if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5 && chk[nx][ny] == true && chk_connetion[nx][ny] == false)
            {
                chk_connetion[nx][ny] = true;
                cnt += make_team(nx, ny);
            }
        }
        return cnt;
 }

void RandomTeam(int depth, int idx, int cnt_Y)
{
    //cout << depth << "\n";
    //s가 아니라 y의 개수로 가지치기
    //y가 4가 넘어가면 더 이상 보는 의미가 없음
    //s가 4가 될 수가 없어서 
    if (cnt_Y==4)
    {
        return;
    }
    //cnt_y가 4까지 도달하지 않고 깊이가 7개까지 왔음
    // 그러므로 연결되어 있는지만 검사

    if (depth == 7)
    {
        
        memset(chk_connetion, false, sizeof(chk_connetion));
        int now = idx - 1;
        int x = mem_list[now].first;
        int y = mem_list[now].second;
        chk_connetion[x][y] = true;
        //cout << idx << " ";
        //모두 연결되어 있는 개수가 7개 이므로 결과값 추가
        if (make_team(x,y) == 7)
          {
            cnt++;
        }
        return;
    }
    //모든 좌표를 백트래킹
    for (int i = idx; i < mem_list.size(); i++)
    {
        pair<int, int>now =mem_list[i];
        int nx = now.first;
        int ny = now.second;
        chk[nx][ny] = true;
        //s인지 y인지 변수 , 이름과 기능이 너의 것과 같음
        int qwer = 0;
        if (arr[nx][ny] == 'Y')
        {
            qwer += 1;
        }
        RandomTeam(depth + 1, i+1, qwer+ cnt_Y);
        chk[nx][ny] = false;

    }


}

int main() {
    string s;
    for (int i = 0; i < 5; i++) {
        cin >> s;
        for (int j = 0; j < 5; j++) {
            arr[i][j] = s[j];
            mem_list.push_back({ i,j });
        }
    }//0부터 24개까지 총 25개 존재
    RandomTeam(0, 0, 0);
    
    cout << cnt;
}