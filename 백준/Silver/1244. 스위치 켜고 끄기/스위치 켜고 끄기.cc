#include<bits/stdc++.h>

using namespace std;

int arr[105];

int main() 
{
    int n; 
    cin >> n;

    for (int i = 1; i <= n; i++) 
        cin >> arr[i];

    int query; 
    cin >> query;

    while (query--)
    {
        int type, idx; 
        cin >> type >> idx;

        if (type == 1)
        {
            for (int i = idx; i <= n; i += idx) 
                arr[i] ^= 1;
        }
        else
        {
            int w = 0;

            while (1 <= idx - w - 1 && idx + w + 1 <= n && arr[idx - w - 1] == arr[idx + w + 1])
                w++;
            for (int i = idx - w; i <= idx + w; i++) 
                arr[i] ^= 1;
        }
    }
    for (int i = 1; i <= n; i++) 
    {
        cout << arr[i];

        if (i % 20 == 0) 
            cout << '\n';
        else
            cout << " ";
    }
}