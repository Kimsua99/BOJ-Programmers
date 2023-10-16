#include <bits/stdc++.h>
using namespace std;

vector<int> board[50001];
int dp[20002];
int answer = 0;
queue<int>q;
int maxNum = 0;

int solution(int n, vector<vector<int>> edge) 
{
    for(int i = 0; i < edge.size(); i++)
    {
        board[edge[i][0]].push_back(edge[i][1]);
        board[edge[i][1]].push_back(edge[i][0]);
    }
    
    q.push(1);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int i = 0; i < board[cur].size(); i++)//현재 위치와 연결된 모든 간선 확인
        {
            if(dp[board[cur][i]] == 0 && board[cur][i] != 1)//방문한 적 없고 1과 연결되지 않은 간선이면
            {
                dp[board[cur][i]] = dp[cur] + 1;//해당 정점 dp 값 +1
                q.push(board[cur][i]);
                maxNum = max(maxNum, dp[board[cur][i]]);//가장 먼 노드 찾기 위한 maxNum
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(maxNum == dp[i])
            answer++;
    }
    
    return answer;
}