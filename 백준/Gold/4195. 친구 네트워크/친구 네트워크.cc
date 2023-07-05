#include <bits/stdc++.h>
using namespace std;

int t, n;

map<string, string> m;
map<string, int> num;

string findParent(string a) //루트 노드 찾기
{
    if (m[a] == a)
        return a;
    return m[a] = findParent(m[a]);

}
void unionParent(string a, string b) 
{
    a = findParent(a);
    b = findParent(b);

    if (a == b)
        return;
    m[b] = a;
    num[a] += num[b];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;
        m.clear(); num.clear();

        for (int i = 0; i < n; i++)
        {
            string a, b;
            cin >> a >> b;
            if (m.count(a) == 0)
            {
                m.insert({ a, a });
                num.insert({ a, 1 });
            }
            if (m.count(b) == 0)
            {
                m.insert({ b, b });
                num.insert({ b, 1 });
            }
            unionParent(a, b);
            cout << num[findParent(a)] << '\n';
        }
    }
}