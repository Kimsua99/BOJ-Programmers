#include <string>
#include <vector>
#include <iostream>

using namespace std;

int check[200];

void dfs(int cur_com, int n, vector<vector<int>> computers)
{
    check[cur_com] = 1;

    for (int i = 0; i < n; i++)
    {
        if (check[i] == 0 && computers[cur_com][i] == 1)//방문한 적이 없고 다른 컴퓨터와 연결되어 있으면
            dfs(i, n, computers);//dfs로 탐색 시작
    }
}

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        if (check[i] == 0)//방문하지 않은 지점이면
        {
            dfs(i, n, computers);
            answer++;//처음 시작 지점이므로 ++하고 연결이 끊어져 다시 돌아와 시작할때도 ++한다.
        }
    }
    return answer;
}