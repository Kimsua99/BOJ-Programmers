#include <bits/stdc++.h>
using namespace std;

int main() 
{
    long long n, m, max = 0;
    int tree[1000001];

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> tree[i];

    sort(tree, tree + n);

    long long low = 0;
    long long high = tree[n - 1];

    while (low <= high) 
    { 
        long long sum = 0;
        long long cut = (low + high) / 2;

        for (int i = 0; i < n; i++) 
        {
            if (tree[i] - cut > 0) sum += tree[i] - cut; 
        }

        if (sum >= m)
        { 
            max = cut; 
            low = cut + 1;
        }
        else {
            high = cut - 1; 
        }
    }

    cout << max; 
}