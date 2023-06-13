#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    for (int i = 0; i < land.size() - 1; i++)
    {
        land[i + 1][0] += max(land[i][1], max(land[i][2], land[i][3]));
        land[i + 1][1] += max(land[i][0], max(land[i][2], land[i][3]));
        land[i + 1][2] += max(land[i][0], max(land[i][1], land[i][3]));
        land[i + 1][3] += max(land[i][0], max(land[i][1], land[i][2]));//각 행을 확인하면서 본인의 열을 제외한 3개의 열의 숫자들 중에 가장 큰 값을 다음 행에 더해준다.
    }

    answer = max(land[land.size() - 1][0], max(land[land.size() - 1][1], max(land[land.size() - 1][2], land[land.size() - 1][3])));//마지막 행의 4개 숫자를 보고 가장 큰 값 출력
    return answer;
}