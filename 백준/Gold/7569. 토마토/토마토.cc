#include <iostream>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

int dx[] = { 0,0,1,-1,0,0 };
int dy[] = { 1,-1,0,0,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
int board[102][102][102];;

int m, n, h;
int day;

queue<pair<pair<int, int>, int>> q;

void bfs()
{
    while (!q.empty())
    {
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int curZ = q.front().second;
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            int nz = curZ + dz[i];

            if (nx >= 0 && ny >= 0 && nz >= 0 && nx < n && ny < m && nz < h && board[nx][ny][nz] == 0)
            {
                q.push({ { nx, ny },nz });
                board[nx][ny][nz] = board[curX][curY][curZ] + 1;
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;

    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> board[i][j][k];

                if (board[i][j][k] == 1)
                {
                    q.push({ { i,j },k });
                }
            }
        }
    }

    bfs();

    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j][k] == 0)
                {
                    cout << -1;
                    return 0;
                }
                else {
                    day = max(board[i][j][k], day);
                }
            }
        }
    }

    cout << day - 1;
}