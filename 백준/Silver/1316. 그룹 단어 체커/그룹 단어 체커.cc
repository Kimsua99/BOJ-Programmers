#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n;
    int cnt = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        bool isgroup = true;
        s.erase(unique(s.begin(), s.end()), s.end());
        sort(s.begin(), s.end());

        for (int j = 0; j < s.size() - 1; j++)
        {
            if (s[j] == s[j + 1])
            {
                isgroup = false;
                break;
            }
        }
        if (isgroup)
            cnt++;
    }

    cout << cnt;
    return 0;
}