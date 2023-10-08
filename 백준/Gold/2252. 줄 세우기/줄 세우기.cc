//위상정렬
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[32001];//간선들의 선후 관계를 담을 배열
int deg[32001]; // 정점마다 들어오는 간선인 indegree 개수를 담을 배열 
int n, m;

queue<int> q;

int main(void)
{
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)//만약 indegree가 0이라면 큐에 넣음
			q.push(i);
	}

	while (!q.empty())
	{
		int cur = q.front();//큐에 있는 가장 위의 정점을 빼서 결과 배열에 넣어줌
		q.pop();
		cout << cur << ' ';

		for (int nxt : adj[cur])//현재 정점과 간선으로 연결된 모든 정점들을 확인
		{
			deg[nxt]--;//해당 정점의 indegree 값을 1 줄임
			if (deg[nxt] == 0)//만약 indegree가 0이면
				q.push(nxt);//큐에 넣음
		}
	}
}
