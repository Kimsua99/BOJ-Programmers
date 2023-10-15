#include <bits/stdc++.h>

using namespace std;


vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int dest) 
{
    vector<int> answer;
    vector<int> cost(n+1, -1);//비용 -1로 초기화
    vector<int> board[100001];
    
    queue<pair<int, int>> q;
    
     for (int i = 0; i < roads.size(); ++i)
    {
        board[roads[i][0]].push_back(roads[i][1]);
        board[roads[i][1]].push_back(roads[i][0]);
    }
    
    q.push({dest, 0});//강철부대가 있는 최종 지점부터 큐에 넣어서 시작
    cost[dest] = 0;//목표 지점이 바로 부대 위치일 수도 있으므로 0으로 설정
    
    while (!q.empty()) 
    {
        int curPos = q.front().first;//현재 위치
        int curCost = q.front().second;//현재 비용
        
        q.pop();
        
        for (auto nxt : board[curPos]) //현 지점과 연결된 노드
        {
            if (cost[nxt] == -1)//아직 방문하지 않았거나 현재 비용+1보다 크면
            {
                q.push({nxt, curCost + 1});//큐에 연결 노드 넣어주고 비용 +1 해줌
                cost[nxt] = curCost + 1;
            }
        }
    }
    
    for (auto s : sources) 
        answer.push_back(cost[s]);
    
    return answer;
}