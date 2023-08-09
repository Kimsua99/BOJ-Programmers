#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;

    priority_queue<int, vector<int>, greater<int>> pq_asc;
    priority_queue<int, vector<int>> pq_des;
    int cnt = 0;

    for(string s : operations)
    {
        if(cnt == 0)
        {
            while(!pq_asc.empty())
                pq_asc.pop();
            while(!pq_des.empty())
                pq_des.pop();
        }
        if(s[0] == 'I')
        {
            pq_des.push(stoi(s.substr(2)));
            pq_asc.push(stoi(s.substr(2)));
            cnt++;
        }
        else
        {
            if(cnt == 0)
                continue;
            if(s[2] == '1')
            {
                pq_des.pop();
                cnt--;
            }
            else
            {
                pq_asc.pop();
                cnt--;
            }
        }
    }
    if(cnt > 0)
    {
        answer.push_back(pq_des.top());
        answer.push_back(pq_asc.top());
    }
    else
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}