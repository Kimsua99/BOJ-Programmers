#include<vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int ans = 0;
    
    int board[101][101];
    int vis[101][101];
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    queue<pair<int, int>>q;
    
    for(int i = 0; i < maps.size(); i++)
    {
        for(int j = 0; j < maps[0].size(); j++)
        {
            q.push({0,0});
            vis[0][0] = 1;
            board[0][0] = 1;

            while(!q.empty())
            {
                int curX = q.front().first;
                int curY = q.front().second;

                q.pop();
                
                for(int k = 0; k < 4; k++)
                {
                    int nx = curX + dx[k];
                    int ny = curY + dy[k];

                    if(nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[0].size())
                        continue;
                    if(maps[nx][ny] == 0 || vis[nx][ny] == 1)
                        continue;
                    
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                    board[nx][ny] = board[curX][curY] + 1;
                }
            }
        }
    }

     if (!board[maps.size() - 1][maps[0].size() - 1])//상대팀 진영에 도착할 수 없는 경우
        ans = -1;
    else
        ans = board[maps.size() - 1][maps[0].size() - 1]; // 상대팀 진영 위치에서의 카운트 값 출력

    return ans;
}