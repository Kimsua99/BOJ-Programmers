//다익스트라 알고리즘
#include <bits/stdc++.h>
using namespace std;

int v, e, st; //정점, 간선, 시작 정점의 번호
vector<pair<int, int>> adj[20005]; //비용, 정점 번호
const int INF = 0x3f3f3f3f;//최댓값
int d[20005];//최단 거리 테이블

int main(void)
{
	cin >> v >> e >> st;
	fill(d, d + v + 1, INF);

	while (e--)
	{
		int u, v, w;
		cin >> u >> v >> w;//u에서 v로 가는 가중치 w
		adj[u].push_back({ w,v });//비용, 거리
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq; 
	//우선순위큐, 최소힙
	d[st] = 0;
	pq.push({ d[st], st });//우선순위 큐에 (비용, 정점 번호) = (0,시작점) 추가

	while (!pq.empty())//큐가 빌 때까지 계속 반복
	{
		auto cur = pq.top();//가장 비용이 적은 쌍이 top이 됨
		pq.pop();

		if (d[cur.second] != cur.first)// top의 정점에 해당하는 테이블 값이 top의 비용과 다르다면
			continue;//다음 반복
		for (auto nxt : adj[cur.second])
		{
			if (d[nxt.second] <= d[cur.second] + nxt.first)//경유보다 기존값이 더 작으면 다음 반복
				continue;
			//경유가 더 비용이 저렴할 경우
			d[nxt.second] = d[cur.second] + nxt.first;//top의 정점에 해당하는 테이블 값에 다음 경로의 비용을 더해줌.
			pq.push({ d[nxt.second], nxt.second });//큐에 해당 값 추가
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (d[i] == INF)//경로가 없을 경우
			cout << "INF\n";//최대 출력
		else
			cout << d[i] << '\n';
	}
}