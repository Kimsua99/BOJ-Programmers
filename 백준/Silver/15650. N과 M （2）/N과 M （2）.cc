#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, idx;
int arr[10];
bool vis[10];

void DFS(int cnt, int idx) 
{
    if (cnt == m) 
    {
        for (int i = 0; i < n; i++)
            if (vis[i]) 
                cout << arr[i] << " ";
        cout << '\n';
    }

    for (int i = idx; i < n; i++) 
    {
        if (vis[i]) 
            continue;
        vis[i] = true;

        DFS(cnt + 1, i + 1);
        vis[i] = false;
    }
}

int main(void) 
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
        vis[i] = false;
    }

    DFS(0, 0);
}
