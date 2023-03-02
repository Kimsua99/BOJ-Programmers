#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[51][51];
bool vis[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int m, n, k;

queue <pair<int, int >> q;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;//테스트 케이스
    while (t--) 
    {
        cin >> m >> n >> k;// 가로길이, 세로길이, 심어져있는 개수

        int x, y;

        for (int i = 0; i < k; i++) 
        {
            cin >> x >> y;
            board[y][x] = 1;//심어져 있는 부분을 1로 설정
        }

        int res = 0; //지렁이 개수

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (board[i][j] == 1 && !vis[i][j]) //이미 방문 한 경우
                {
                    vis[i][j] = true;
                    q.push({ i,j });//방문 표시 남기고 푸시
                    
                    while (!q.empty())
                    {
                        auto cur = q.front(); q.pop();//현재는 큐의 맨 앞이고 팝해서 빼냄

                        for (int dir = 0; dir < 4; dir++)//상하좌우 돌면서 확인
                        {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m)//범위 밖이면 다음 반복
                                continue;
                            if (vis[nx][ny] || board[nx][ny] != 1)//방문했으면 다음 반복
                                continue;

                            vis[nx][ny] = true;//방문 표시 남기고 푸시
                            q.push({ nx,ny });
                        }
                    }
                    res++;//지렁이 개수 하나 더 증가
                }
            }
        }
        cout << res << "\n";
        for (int i = 0; i < n; i++) 
        {
            fill(board[i], board[i] + m, 0);
            fill(vis[i], vis[i] + m, false);//다음 테스트 케이스 돌아야 하므로 기존 판 모두 0으로 바꾸고 방문 여부도 false로 변경
        }
    }
    return 0;
}