#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;//거리가 무한임을 나타냄.
int d[105][105];
int n, m;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;//도시, 버스

    for (int i = 1; i <= n; i++)
        fill(d[i], d[i] + 1 + n, INF);

    while (m--) 
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    for (int i = 1; i <= n; i++)
        d[i][i] = 0;//0으로 채움.

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);//그냥 가는 것과 거쳐 가는 것 중 더 비용이 짧은 것 채택

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) 
        {
            if (d[i][j] == INF) 
                cout << "0 ";
            else 
                cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
}