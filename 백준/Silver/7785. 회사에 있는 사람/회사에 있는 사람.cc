#include <bits/stdc++.h>
using namespace std;

set<string> s;
int n; 
string name;
string st;
int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> st;
        if (st == "enter")
            s.insert(name);
        if (st == "leave")
        {
            s.erase(name);
        }
    }

    vector<string> ans(s.begin(), s.end());

    sort(ans.begin(), ans.end(), greater<string>());

    for (auto x : ans) 
        cout << x << '\n';
}