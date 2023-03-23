#include <bits/stdc++.h>
using namespace std;

int n, k;//n개의 동전 종류, 가치의 합 k
int a[15];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) //n종류를 for문 돌면서 배열에 입력받음. 이때 가치는 오름차순으로 입력해야함.
        cin >> a[i];

    for (int i = n - 1; i >= 0; i--) //가장 가치가 높은 수부터 가치 낮은 동전까지 차례로 반복문 실행
    {
        ans += k / a[i];//결과 값은 가치합을 각 동전의 가치로 나눈 값을 더한 결과.
        k %= a[i];//k는 각 동전의 가치로 가치합을 나눴을 때 남은 결과가 됨. 
    }

    cout << ans;
}
