#include <bits/stdc++.h>
using namespace std;

int n, ans;

int a[501][501];
int d[501][501];

int main()
{
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) 
    { // 정수 삼각형 입력 받음
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
    d[1][1] = a[1][1]; // 맨 꼭대기 층은 같음

    for (int i = 2; i <= n; i++) 
    { // 2번째 줄 부터 시작
        for (int j = 1; j <= i; j++) 
        { // 1번째 칸 부터 시작
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j];
            // 윗 줄 중 바로 위쪽, 왼쪽 대각선 중 큰 것을 골라
            // 자기 칸의 값과 더함.
        }
    }
    for (int i = 1; i <= n; i++) 
    { // 마지막 줄 중 가장 큰 것을 고름
        if (ans < d[n][i])
            ans = d[n][i];
    }
    cout << ans; // 결과 출력
}
