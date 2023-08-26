#include <bits/stdc++.h>
using namespace std;

int r, c, n;
char board[201][201];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> q;

int main()
{
	cin >> r >> c >> n;

	for (int i = 0; i < r; i++)
	{
		getchar();
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
		}
	}

	if (n % 2 == 0)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				printf("O");
			}
			printf("\n");
		}
		return 0;
	}

	int t = 1;//초

	while (t < n)
	{
		for (int i = 0; i < r; i++)//기존 폭탄 있던 지점 큐에 넣음. 
		{
			for (int j = 0; j < c; j++)
			{
				if (board[i][j] == 'O')
					q.push({ i, j });
			}
		}

		for (int i = 0; i < r; i++)//모든 지점에 폭탄 설치
		{
			for (int j = 0; j < c; j++)
			{
				if (board[i][j] == '.')
					board[i][j] = 'O';
			}
		}

		while (!q.empty())
		{
			int curX = q.front().first;
			int curY = q.front().second;

			q.pop();

			board[curX][curY] = '.';//현재 칸도 폭발하므로 빈칸으로 바꿔줌.

			for (int dir = 0; dir < 4; dir++)//상하좌우
			{
				int nx = curX + dx[dir];
				int ny = curY + dy[dir];

				if (nx < 0 || ny < 0 || nx >= r || ny >= c)//벽일 경우
					continue;
				board[nx][ny] = '.';//상하좌우 폭탄 터져 빈칸 됨.
			}
		}
		t += 2;//폭탄 설치 및 폭발 했으므로 2초 지남.
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << board[i][j];
		}
		cout << '\n';
	}

}