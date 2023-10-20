#include <string>
#include <vector>

using namespace std;

int vis[201];
int answer = 0;

void dfs(int st, int n, vector<vector<int>> computers)
{
    vis[st] = 1;
    
    for(int i = 0; i < n; i++)
    {
        if(vis[i] == 0 && computers[st][i] == 1)
        {
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) 
{
    
    for(int i = 0; i < n; i++)
    {
        if(vis[i] == 0)
        {
            dfs(i, n, computers);
            answer++;
        }
    }
    
    
    return answer;
}