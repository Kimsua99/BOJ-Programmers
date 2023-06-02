#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    int day;
    vector<int> d;
    queue<int> q;

    for (int i = 0; i < progresses.size(); i++)
    {
        if ((100 - progresses[i]) % speeds[i] != 0)
            day = (100 - progresses[i]) / speeds[i] + 1;
        else
            day = (100 - progresses[i]) / speeds[i];
        d.push_back(day);
    }

    q.push(d[0]);
    for (int i = 1; i < d.size(); i++)
    {
        if (d[i] <= q.front())
        {
            q.push(d[i]);
        }
        else
        {
            answer.push_back(q.size());
            while(!q.empty())
                q.pop();
            q.push(d[i]);
        }
    }

    if(!q.empty()) 
        answer.push_back(q.size());
    return answer;
}