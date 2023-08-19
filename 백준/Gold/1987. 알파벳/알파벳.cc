#include<bits/stdc++.h>
using namespace std;

char board[21][21];
bool vis[26]; 

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int r, c;
int ans = 0;

void dfs(int x, int y, int cnt) 
{
	if (ans < cnt) //최댓값 구하기
		ans = cnt;

	for (int i = 0; i < 4; i++) //상하좌우 확인
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < r && ny >= 0 && ny < c)//범위 내에 있으면서
		{
			if (vis[board[nx][ny] - 'A'] == false)//방문하지 않은 지역이면
			{
				vis[board[nx][ny] - 'A'] = true;//방문 체크
				dfs(nx, ny, cnt + 1);//cnt 증가하고 dfs 돌기
				vis[board[nx][ny] - 'A'] = false;//백트래킹
			}
		}
	}
}

int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++) 
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
		}
	}

	vis[board[0][0] - 'A'] = true;//0,0이 시작점이므로 해당 지점 방문 체크

	dfs(0, 0, 1);//0,0부터 시작하고 처음 지점 방문 했으니까 cnt 1로 잡고 시작

	cout << ans;
}
