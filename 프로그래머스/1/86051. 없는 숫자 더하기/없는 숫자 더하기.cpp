#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    numbers.resize(numbers.size()+1);
    vector<int> arr(10);
    for(int i=0;i<numbers.size();i++)
    {
        arr[numbers[i]]++;
    }
    for(int i=0;i<=9;i++)
    {
        if(arr[i]==0)
        {
            answer+=i;
        }
    }
    return answer;
}