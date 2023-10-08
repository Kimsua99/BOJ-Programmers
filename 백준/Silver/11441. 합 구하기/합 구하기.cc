#include <bits/stdc++.h>
using namespace std;
int sum[100005];
int n, m, s, e;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        sum[i] = sum[i - 1] + num;
    }
    cin >> m;
    while (m--) {
        cin >> s >> e;
        cout<<sum[e]-sum[s-1]<<'\n';
    }
}