#include <bits/stdc++.h>
using namespace std;

int n, m;
int a, b;

int board[1001][1001] = { 0 };
int vis[1001][1001] = { 0 };

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> q;

void bfs(int x, int y)
{
    q.push({ x, y });
    vis[x][y] = 1;

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (vis[nx][ny] == 0 && board[nx][ny] != 0)
                {
                    vis[nx][ny] = vis[curX][curY] + 1;
                    q.push({ nx, ny });
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
            {
                a = i;
                b = j;
            }
        }
    }

    bfs(a, b);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << vis[i][j] - 1 << " ";
            }
        }
        cout << "\n";
    }
}