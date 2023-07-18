#include <bits/stdc++.h>
using namespace std;

using namespace std;

int N, M;
int MAP[301][301];
int C_MAP[301][301];
bool Visit[301][301];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
        }
    }
}

void BFS(int a, int b)
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(a, b));
    Visit[a][b] = true;

    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (Visit[nx][ny] == false && MAP[nx][ny] != 0)
                {
                    Visit[nx][ny] = true;
                    Q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int Melt(int x, int y)//주변에 0인 지점의 개수 반환
{
    int Cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (MAP[nx][ny] == 0) Cnt++;
    }
    return Cnt;
}

void Solution()
{
    int Year = 0;
    while (1)
    {
        int Land_Cnt = 0;
        memset(Visit, false, sizeof(Visit));//초기화
        memset(C_MAP, 0, sizeof(C_MAP));//초기화

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (MAP[i][j] != 0 && Visit[i][j] == false)
                {
                    Land_Cnt++;
                    BFS(i, j);
                }
            }
        }

        if (Land_Cnt >= 2) { cout << Year << endl; break; }//두덩이 이상이면 시간 출력
        if (Land_Cnt == 0) { cout << 0 << endl; break; }//아닐 경우 0 출력

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (MAP[i][j] != 0)
                {
                    C_MAP[i][j] = MAP[i][j] - Melt(i, j);//주변 0인 지점 개수만큼 높이를 빼줌.
                    if (C_MAP[i][j] < 0) C_MAP[i][j] = 0;//0보다 작아지면 0으로 세팅
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                MAP[i][j] = C_MAP[i][j];//덮어씀
            }
        }

        Year++;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
}
