#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

int board[100][100];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n, m;


int bfs(int x, int y)
{
	queue <pair<int, int>> q;

	q.push({ x, y });

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (board[nx][ny] == 0)
				continue;
			if (board[nx][ny] == 1)
			{
				board[nx][ny] = board[x][y] + 1;
				q.push({ nx, ny });
			}

		}

	}

	return board[n - 1][m - 1];
}
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &board[i][j]);
		}
	}

	cout << bfs(0,0) << endl;
	
	return 0;
}
