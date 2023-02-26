#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k , n, sum = 0;
    cin >> k;
    stack<int> s;

    while (k--)
    {
        cin >> n;
        
        if (n != 0)
            s.push(n);
        else
            if (!s.empty())
                s.pop();
    }

    while (!s.empty()) 
    {
        sum += s.top();
        s.pop();
    }
    cout << sum;
}