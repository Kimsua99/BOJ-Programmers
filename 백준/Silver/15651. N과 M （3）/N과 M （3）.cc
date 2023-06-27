#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
int arr[10];
vector<int> v;

void DFS(int cnt) 
{
    if (cnt == m) 
    {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) 
    {
        v.push_back(arr[i]);
        DFS(cnt + 1);
        v.pop_back();
    }
}

int main(void) 
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    DFS(0);
}
