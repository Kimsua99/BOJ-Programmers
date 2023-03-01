#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dist[305][305];

int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int t, n, x, y, xx, yy;

queue <pair<int, int >> Q;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;//테스트케이스 수
    while (t--) 
    {
        cin >> n;//체스판의 한변의 길이

        for (int i = 0; i < n; i++) 
            fill(dist[i], dist[i] + n, -1);//전체를 -1로 설정

        cin >> x >> y;//현재 좌표

        dist[x][y] = 0;
        Q.push({ x, y });

        cin >> xx >> yy;;//이동할 좌표

        while (!Q.empty()) 
        {
            auto cur = Q.front(); Q.pop();//현재 좌표
            for (int dir = 0; dir < 8; dir++) //이동 가능 지점이 8군데이므로 8번 반복
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (dist[nx][ny] >= 0) continue;

                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({ nx, ny });
            }
        }
        cout << dist[xx][yy] << "\n";
    }
}