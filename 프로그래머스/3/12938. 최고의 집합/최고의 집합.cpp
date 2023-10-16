#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, int s) 
{
    vector<int> answer;
    int rest = s;
    
    if(n > s)
    {
        answer.push_back(-1);
        return answer;
    }
    while(rest != 0)
    {
        int a;
        a = rest/n;
        answer.push_back(a);
        rest -= a;
        n--;
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}