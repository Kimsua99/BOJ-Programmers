#include <bits/stdc++.h>
using namespace std;

vector<int> p(303, -1);

int find(int x) //루트 노드 찾기
{
    if (p[x] < 0) 
        return x;

    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) 
{
    u = find(u); 
    v = find(v);

    if (u == v) //루트가 같음 = 같은 그룹으로 연결되어 있음.
        return 0;

    if (p[u] == p[v])
        p[u]--;

    if (p[u] < p[v])
        p[v] = u;

    else 
        p[u] = v;

    return 1;
}

int v, e;
tuple<int, int, int> edge[100005];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v;//논의 수(정점의 수)
    // 가상의 v+1번째 정점과 연결
    for (int i = 1; i <= v; i++) 
    {
        int cost;
        cin >> cost;//논에 우물을 팔 때 드는 비용
        edge[e++] = { cost, i, v + 1 };
    }

    for (int i = 1; i <= v; i++) 
    {
        for (int j = 1; j <= v; j++) 
        {
            int cost;
            cin >> cost;//논들 사이에 물을 끌어오는 비용

            if (i >= j)
                continue;

            edge[e++] = { cost, i, j };
        }
    }
    v++; // 가상의 정점까지 포함해야 하므로 정점 수를 1 증가시킴
    sort(edge, edge + e);

    int cnt = 0;
    int ans = 0;

    for (int i = 0; i < e; i++)
    {
        int a, b, cost;
        tie(cost, a, b) = edge[i];

        if (!is_diff_group(a, b)) //같은 그룹이 아니면
            continue;
        ans += cost;//같은 그룹이면 해당 간선의 비용 결과에 더해줌.
        cnt++;
        if (cnt == v - 1)//정점 - 1 = 간선이 되면 반복문 종료
            break;
    }
    cout << ans;
}