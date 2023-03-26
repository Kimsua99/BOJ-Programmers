#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100005];
int mn = 0x7fffffff;//차이 값을 처음에 제일 큰 값으로 줌

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m; //n개로 이루어진 수열, 두 수의 차이는 m 이상

    for (int i = 0; i < n; i++) 
        cin >> a[i];

    sort(a, a + n);//a 배열 오름차순 정렬하기
    int en = 0;//j가 될 지점 0으로 지정

    for (int st = 0; st < n; st++) //0부터 시작해서 n까지 반복
    {
        while (en < n && a[en] - a[st] < m) //배열 벗어나지 않으면서 두 값의 차이가 m보다 작으면 en을 이동해야함.
            en++;
        if (en == n) //en이 배열 맨 끝에 있으면 
            break; // en이 범위를 벗어날 시 종료

        mn = min(mn, a[en] - a[st]);// 두 수의 차이 값은 제일 큰 수와 두 수의 차이 중 작은 값 택함.
    }
    cout << mn;
}