#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) 
{
    long long answer = 0;
    
    priority_queue<int> pq(works.begin(), works.end());
    int tmp;
    for(int i = 0; i < n; i++)
    {
        tmp = pq.top();
        pq.pop();
        tmp--;
        pq.push(tmp);
    }
    
    while(!pq.empty())
    {
        tmp = pq.top();
        pq.pop();
        if(tmp < 0)
            tmp = 0;
        answer += tmp * tmp;
    }
    
    return answer;
}