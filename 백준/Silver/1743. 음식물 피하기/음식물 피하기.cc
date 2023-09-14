#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int board[101][101] = {0};
int vis[101][101] = {0};

int n, m, k;
int cnt = 0;
int ans = 0;
int main(void)
{
	cin >> n >> m >> k;

	while (k--)
	{
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (board[i][j] == 1 && vis[i][j] == false)
			{
				queue<pair<int, int>>q;
				q.push({ i,j });
				vis[i][j] = true;
				cnt = 1;

				while (!q.empty())
				{
					int curX = q.front().first;
					int curY = q.front().second;

					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int nx = curX + dx[k];
						int ny = curY + dy[k];

						if (nx <= 0 || nx > n || ny <= 0 || ny > m)
							continue;
						if (vis[nx][ny] == true || board[nx][ny] == 0)
							continue;
						cnt++;
						q.push({ nx,ny });
						vis[nx][ny] = true;
					}
				}
			}
			if (cnt > ans)
				ans = cnt;
		}
	}

	cout << ans;
}
