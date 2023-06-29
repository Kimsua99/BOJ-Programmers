#include <bits/stdc++.h>
using namespace std;

int n, s, tot;
int a[100005];
int mn = 0x7fffffff;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int en = 0;

    tot = a[0];

    for (int st = 0; st < n; st++)
    {
        while (en < n && tot < s)
        {
            en++;
            if (en != n)
                tot += a[en];
        }
        if (en == n)
            break;
        mn = min(mn, en - st + 1);//개수 구하기
        tot -= a[st];//맨 앞지점 뺐는데도 합이 s 이상인지 확인하기 위해
    }
    if (mn == 0x7fffffff)
        mn = 0;
    cout << mn;

}