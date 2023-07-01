#include <bits/stdc++.h>
using namespace std;

int N, K, ans;
int cnt[100005];  // cnt[i]: i번째 수의 등장 횟수
int a[200005];    // 수열 a_i를 저장하는 배열

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i) 
        cin >> a[i];

    int en = 0;

    ++cnt[a[en]];

    for (int st = 0; st < N; ++st) 
    {
        while (en + 1 != N && cnt[a[en + 1]] < K)//en + 1이 수열의 끝을 넘지 않으며 해당 자리의 등장 횟수 1 증가해도 k 넘지 않을 경우
        {
            ++en;
            cnt[a[en]]++; 
        }
        ans = max(ans, en - st + 1);
        cnt[a[st]]--;
    }
    cout << ans;
}