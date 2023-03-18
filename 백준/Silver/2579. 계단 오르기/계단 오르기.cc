#include <bits/stdc++.h>
using namespace std;

int N;
int DP[301];
int arr[301] = { 0, };

int main() 
{
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    DP[1] = arr[1];

    DP[2] = arr[1] + arr[2];

    DP[3] = max(arr[1], arr[2]) + arr[3];

    for (int j = 4; j <= N; j++) 
    {
        DP[j] = max(DP[j - 2] + arr[j], DP[j - 3] + arr[j - 1] + arr[j]);
    }

    cout << DP[N];
    return 0;
}