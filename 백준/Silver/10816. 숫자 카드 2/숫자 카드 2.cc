#include <bits/stdc++.h>
using namespace std;

int a[500005];
int n;

int lower_idx(int target, int len) //가장 왼쪽의 위치를 구함
{
    int st = 0;
    int en = len;
    while (st < en) 
    {
        int mid = (st + en) / 2;
        if (a[mid] >= target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int upper_idx(int target, int len) //가장 오른쪽의 위치를 구함
{
    int st = 0;
    int en = len;
    while (st < en) 
    {
        int mid = (st + en) / 2;
        if (a[mid] > target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int m;
    cin >> m;
    while (m--) 
    {
        int t;
        cin >> t;
        cout << upper_idx(t, n) - lower_idx(t, n) << '\n';//가장 오른쪽 위치에서 가장 왼쪽 위치 뺀 값이 위치의 차이 =  해당 수의 개수
    }
}