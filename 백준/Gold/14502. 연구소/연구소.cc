#include<bits/stdc++.h>
using namespace std;

int n, m; 
int board[8][8]; 
int temp[8][8];
int ans = 0;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void virus(int x, int y) //바이러스 살포
{
    for (int i = 0; i < 4; i++) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m)//범위 안이면서
        {
            if (temp[nx][ny] == 0) //빈 공간일 경우
            {
                temp[nx][ny] = 2;//바이러스 공간으로 바꿔줌
                virus(nx, ny);//재귀
            }
        }
    }
}

void wall(int x, int y, int cnt)
{
    if (cnt == 3)// 벽을 3개 세웠을 경우
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                temp[i][j] = board[i][j];//기존 맵 임시 맵에 복사해줌.
            }
        }

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (temp[i][j] == 2) //바이러스 공간이면
                    virus(i, j);//바이러스 살포
            }
        }

        int cnt = 0;//안전 구역 카운트

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (temp[i][j] == 0)//빈 공간이면
                    cnt++;//안전구역 ++
            }
        }
        if (cnt > ans)//최대 안전 구역 결과 출력
            ans = cnt;

        return;
    }

    for (int i = x; i < n; i++)// 벽 세우기
    {
        for (int j = (i == x) ? y : 0; j < m; j++)//i랑 x가 같을 경우 j == y 다를 경우 j == 0
        {
            if (board[i][j] == 0)//빈 공간이면
            {
                board[i][j] = 1;//벽 세움
                wall(i, j, cnt + 1);//벽 카운트 + 1하고 재귀로 벽 추가로 세우기
                board[i][j] = 0;//백트래킹 위해 0으로 바꿈.
            }
        }
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	wall(0, 0, 0);//시작 x, 시작 y, 벽 카운트

	cout << ans;//안전 구역 출력
}
