#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string s;

    cin >> s;

    int o = 0, z = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != s[i + 1])
        {
            if (s[i] == '0')
                z++;
            else
                o++;
        }
    }
    cout << min(o, z);
}