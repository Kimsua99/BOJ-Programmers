#include <bits/stdc++.h>
using namespace std;

int T, N, M;
vector<int> v;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> T;

	while (T--)
	{
		int dp[10001];
		for (int i = 0; i < 10001; i++)
		{
			dp[i] = 0;
		}
		v.clear();

		dp[0] = 1;

		cin >> N;

		for (int i = 0; i < N; i++)
		{
			int num;
			cin >> num;
			v.push_back(num);
		}

		cin >> M;

		for (int i = 0; i < N; i++) 
		{
			for (int j = v[i]; j <= M; j++)
			{
				dp[j] += dp[j - v[i]];
			}
		}

		cout << dp[M] << '\n';
	}
}