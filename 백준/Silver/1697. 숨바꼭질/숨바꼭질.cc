#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

bool vis[100001];
int n, k;

void bfs(int n)
{
	queue<pair<int, int>> q;
	q.push({ n, 0 });//수빈이 현재 위치와 이동 횟수 삽입

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		if (x == k)//동생의 위치에 도달했다면
		{
			cout << y;
			break;
		}

		if (x + 1 >= 0 && x + 1 < 100001)//한 칸 앞으로 이동한 경우
		{
			if (!vis[x + 1])//방문하지 않았으면
			{
				vis[x + 1] = true;//방문 체크
				q.push({ x + 1, y + 1 });//큐에 넣고 이동++
			}
		}
		if (x - 1 >= 0 && x - 1 < 100001)//한 칸 뒤로 이동한 경우
		{
			if (!vis[x - 1])//방문하지 않았으면
			{
				vis[x - 1] = true;//방문 체크
				q.push({ x - 1, y + 1 });//큐에 넣고 이동++
			}
		}
		if (2*x >= 0 && 2 * x < 100001)//순간이동한 경우
		{
			if (!vis[2 * x])//방문하지 않았으면
			{
				vis[2 * x] = true;//방문 체크
				q.push({ 2 * x, y + 1 });//큐에 넣고 이동++
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;//수빈 위치, 동생 위치

	vis[n] = true;
	bfs(n);
	return 0;
}
