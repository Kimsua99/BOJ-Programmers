#include <iostream>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int board[1001][1001];

int m, n;
int day = -1;

queue<pair<int, int>>q;
void bfs()
{
    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (ny >= 0 && nx >= 0 && nx < n && ny < m && board[nx][ny] == 0)
            {
                q.push({ nx, ny });
                board[nx][ny] = board[curX][curY] + 1;
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 1)
            {
                q.push({ i,j });
            }
        }
    }

    bfs();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)//안 익은게 발견되면 -1 출력
            {
                cout << -1;
                return 0;
            }
            else
            {
                day = max(board[i][j], day);
            }
        }
    }
    cout << day - 1;
}