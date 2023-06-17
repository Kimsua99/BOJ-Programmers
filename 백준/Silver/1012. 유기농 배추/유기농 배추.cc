#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

int board[51][51] = { 0 };
bool vis[51][51] = { 0 };

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int t, n, m, k, x, y, cnt;
vector<int> v;
void bfs(int n, int m)
{
	queue<pair<int, int>> q;
	cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 1 && vis[i][j] == false)
			{
				q.push({ i, j });
				vis[i][j] = true;
				cnt++;

				while (!q.empty())
				{
					int curX = q.front().first;
					int curY = q.front().second;

					q.pop();
					
					for (int k = 0; k < 4; k++)
					{
						int nx = curX + dx[k];
						int ny = curY + dy[k];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
							continue;
						if (board[nx][ny] == 0 || vis[nx][ny] == true)
							continue;
						q.push({ nx, ny });
						vis[nx][ny] = true;
						//board[curX][curY] = board[nx][ny] + 1;
					}

				}
			}
		}
	}

	v.push_back(cnt);
	
}
void reset() 
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			board[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vis[i][j] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n >> m >> k;

		for (int j = 0; j < k; j++)
		{
			cin >> x >> y;
			board[x][y] = 1;
		}

		bfs(n, m);
		reset();
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
}
