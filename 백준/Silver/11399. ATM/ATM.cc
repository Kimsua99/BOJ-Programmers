#include <bits/stdc++.h>
using namespace std;

int n;
int p[1005];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sort(p, p + n);

    int ans = 0;
    int res = 0;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        ans += p[i];
        v.push_back(ans);
    }
    for (int i = 0; i < n; i++)
    {
        res += v[i];
    }
    cout << res;
}