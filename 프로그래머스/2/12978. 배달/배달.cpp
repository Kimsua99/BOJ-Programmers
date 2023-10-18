#include <bits/stdc++.h>
using namespace std;

vector<int> dist;//최단 거리 테이블
vector<pair<int, int>> v[55];//비용, 정점 번호
const int INF = 0x3f3f3f3f;//최댓값

void Dijkstra(int n)
{
    priority_queue<pair<int, int>> pq;//비용, 정점 번호
    pq.push({ 0,1 });
    dist[1] = 0;

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;

        pq.pop();

        for (int i = 0; i < v[cur].size(); i++)//현재 정점과 이어져있는 모든 정점들 확인
        {
            int nxt = v[cur][i].first;//연결된 정점
            int nCost = v[cur][i].second;//연결 정점까지의 비용

            if (dist[nxt] > cost + nCost)//경유하는 것이 더 비용 저렴할 경우
            {
                dist[nxt] = cost + nCost;//연결 정점의 테이블 비용을 경유해서 가는 비용으로 갱신
                pq.push({ dist[nxt], nxt });//큐에 다음 지점 비용, 정점 넣어줌
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K)
{
    int answer = 0;

    dist.resize(N + 1, INF);

    for (int i = 0; i < road.size(); i++)
    {
        int st = road[i][0];
        int en = road[i][1];
        int cost = road[i][2];

        v[st].push_back({ en, cost });
        v[en].push_back({ st, cost });
    }

    Dijkstra(N);


    for (int i = 1; i <= N; i++)
    {
        if (dist[i] <= K)//k시간 이하로 배달이 가능할 경우에만
            answer++;//음식 주문 받기
    }
    return answer;
}