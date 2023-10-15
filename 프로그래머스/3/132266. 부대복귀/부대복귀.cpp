#include <bits/stdc++.h>

using namespace std;


vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int dest) 
{
    vector<int> answer;
    vector<int> cost(n+1, -1);//비용 -1로 초기화
    vector<int> board[100001];
    
    queue<pair<int, int>> q;
    
    for(auto a : roads)//연결된 노드 돌면서 board 벡터에 넣어줌
    {
        board[a[0]].push_back(a[1]);
        board[a[1]].push_back(a[0]);
    }
    
    q.push({dest, 0});//강철부대가 있는 최종 지점부터 큐에 넣어서 시작
    cost[dest] = 0;
    
    while (!q.empty()) 
    {
        int curPos = q.front().first;//현재 위치
        int curCost = q.front().second;//현재 비용
        
        q.pop();
        
        for (auto nxt : board[curPos]) //현 지점과 연결된 노드
        {
            if (cost[nxt] == -1 || cost[nxt] > curCost + 1)//아직 방문하지 않았거나 연결이 된 노드일 경우
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