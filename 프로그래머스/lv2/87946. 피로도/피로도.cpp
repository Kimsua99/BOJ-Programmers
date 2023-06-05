#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool visited[8] = { 0 };//1차원 배열, 모두 0으로 세팅한다.

void dfs(int cnt, int k, vector<vector<int>>& dungeons) //던전을 완전탐색으로 순회해야 하므로 dfs 사용
{
    if (cnt > answer) 
        answer = cnt;//dfs를 돌면서 저절로 가장 많이 방문한 횟수 저장됨

    for (int i = 0; i < dungeons.size(); i++)
    {
        if (!visited[i] && dungeons[i][0] <= k) //방문한 적이 없는 경우 -> 0일 경우 && 각 던전의 최소 피로도가 k보다 작거나 같을 경우
        {
            visited[i] = true;//방문 표식을 남긴다.
            dfs(cnt + 1, k - dungeons[i][1], dungeons);//방문 1회 했으므로 카운트 값 증가, 현재 피로도에서 해당 던전의 소모 피로도 감소, dfs 진행
            visited[i] = false;//다음 방문을 위해 false로 변경
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) //피로도, 던전(최소 피로도, 소모 피로도)
{
    dfs(0, k, dungeons);
    return answer;
}