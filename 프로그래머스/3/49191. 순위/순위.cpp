#include <bits/stdc++.h>
using namespace std;

bool graph[101][101];

int solution(int n, vector<vector<int>> results) 
{
    int answer = 0;
    
    for(int i = 0; i < results.size();i++)
    {
        graph[results[i][0]][results[i][1]] = true;
    }


    for(int k=1; k<=n;k++)
    {
        for(int i=1; i<=n;i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(graph[i][k] && graph[k][j])//i가 k를 이기고 k가 j를 이기면
                    graph[i][j] =true;//i가 j를 이김
            }
        }
    }
    
    for(int i = 1; i <= n;i++)
    {
        int count = 0;
        
        for(int j = 1 ; j <= n; j++)
        {
            if(graph[i][j] || graph[j][i])//승패 결과 카운트
                count++;
        }
        
        if(count == n-1)//모든 선수들이랑 겨뤘을 경우 순위 도출 가능
            answer++;
    }

    return answer;
}