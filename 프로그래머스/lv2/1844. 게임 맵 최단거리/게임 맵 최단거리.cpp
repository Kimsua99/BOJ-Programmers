#include<vector>
#include<queue>
using namespace std;

int n, m;//열, 행

int board[101][101] = { 0 }; // 진행 거리 체크
bool vis[101][101] = { 0 }; // 방문 여부 체크

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pair<int, int>> q;

int solution(vector<vector<int> > maps)
{
    int answer = 0;

    n = maps[0].size();//열
    m = maps.size();//행

    vis[0][0] = true;//처음 지점 방문 체크해줌.
    board[0][0] = 1;
    q.push(make_pair(0,0));//처음 지점 큐에 넣음.

    //bfs 시작
    while (!q.empty())//큐가 빌 때 까지 큐의 front를 pop으로 빼내고 상하좌우 살피면서 큐에 push 해주는 작업 반복
    {
        int curX = q.front().first;//맨 앞 좌표
        int curY = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)//상하좌우 확인
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)//범위 벗어난 경우 다음 반복
                continue;

            if (vis[nx][ny] || maps[nx][ny] == 0)//이미 방문했거나 벽인 경우 다음 반복
                continue;

            vis[nx][ny] = true;//방문 표시 남김
            q.push(make_pair(nx,ny));//큐에 넣음
            board[nx][ny] = board[curX][curY] + 1;
        }
    }

    if (!board[m - 1][n - 1])
        answer = -1;
    else
        answer = board[m - 1][n - 1];

    return answer;
}