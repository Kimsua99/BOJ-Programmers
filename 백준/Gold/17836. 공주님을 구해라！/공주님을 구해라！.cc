#include <bits/stdc++.h>

using namespace std;

int board[110][110];
int dist[110][110];
bool vis[110][110];

int N, M, T;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

pair<int, int> sword;

void bfs() 
{
    queue<pair<int, int>> q;

    q.push({1,1});
    vis[1][1] = true;//용사 위치

    while (!q.empty()) 
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (nx <= 0 || ny <= 0 || nx > N || ny > M)
                continue;
            if (vis[nx][ny] == true || board[nx][ny] == 1)
                continue;

            q.push({nx,ny});
            vis[nx][ny] = true;
            dist[nx][ny] = dist[curX][curY] + 1;
        }
    }
}

int main() 
{
    cin >> N >> M >> T;

    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 2)
                sword = make_pair(i, j);
        }
    }

    bfs();

    int use_sword = INT_MAX, not_use_sword = INT_MAX;

    if (dist[sword.first][sword.second] != 0)//검 위치를 방문한 경우 
        use_sword = dist[sword.first][sword.second] + (N - sword.first) + (M - sword.second);

    if (dist[N][M] != 0)//공주 위치 방문한 경우
        not_use_sword = dist[N][M];

    int answer = min(use_sword, not_use_sword);

    if (answer > T)//t보다 크면 실패
        cout << "Fail";

    else 
        cout << answer;
}