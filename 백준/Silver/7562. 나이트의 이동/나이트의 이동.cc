#include <iostream>
#include <queue>

using namespace std;

int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };//(2,1) / (1,2) / (-1,2) / (-2,1) ...

int board[305][305] = { 0 };
bool vis[305][305] = { 0 };

int t, n, x, y, xx, yy;

queue <pair<int, int>> q; 
void bfs(int n)
{
    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) 
                continue;
            if (board[nx][ny] >= 1 || vis[nx][ny] == true) 
                continue;
            board[nx][ny] = board[curX][curY] + 1;
            q.push({ nx, ny });
            vis[nx][ny] = true;
        }
    }
}
void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
            vis[i][j] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;
        cin >> x >> y;
        cin >> xx >> yy;

        board[x][y] = 1;
        vis[x][y] = true;
        q.push({ x,y });

        bfs(n);
        cout << board[xx][yy] - 1 << '\n';
        reset();
    }
}