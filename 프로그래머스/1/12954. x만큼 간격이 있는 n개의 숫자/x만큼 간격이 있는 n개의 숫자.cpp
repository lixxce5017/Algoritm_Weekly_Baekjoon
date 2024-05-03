#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    long long num=1;
    long long nx=x;
    while(answer.size()<n)
    {
        answer.push_back(nx);
        num++;
        nx=x*num;
        
    }
    return answer;
}