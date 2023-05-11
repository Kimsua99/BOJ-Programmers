#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//완전 탐색 -> 가능한 경우의 수를 모두 체크해서 정답을 찾음 ex) 브루트 포스, 순열, 재귀, bfs, dfs ...
//1. 모든 배열을 돌면서 모든 명함이 다 들어갈 수 있는 가로와 세로의 최대 길이를 구한다.
//2. 하지만 가능한 가장 작은 지갑을 만들기 때문에 가로나 세로 중 하나는 최대한 짧아야 한다.
//3. 명함의 긴 변 중 가장 긴 변 * 명함의 짧은 변 중 가장 긴 변 = 가장 작은 지갑 이다.

int solution(vector<vector<int>> sizes) 
{
    int left = 0;// 가로 길이
    int right = 0;// 세로 길이
    
    for (int i = 0; i < sizes.size(); ++i) //모든 벡터 배열을 돌면서 실행
    {
        left = max(left, max(sizes[i][0], sizes[i][1]));//가로는 각 명함의 가로 세로 중 더 긴 것들 모은 담에 그 중에 가장 큰 값이다. ex) 1. 60, 2. 70, 3. 60, 4. 80 -> 가장 큰 값은 80
        right = max(right, min(sizes[i][0], sizes[i][1]));//세로는 각 명함의 가로 세로 중 더 짧은 것들을 모은 담에 그 중에 가장 큰 값이다 ex) 1. 50, 2. 30, 3. 30, 4. 40 -> 가장 큰 값은 50
    }
    
    return left * right;// 80 * 50 = 4000
}