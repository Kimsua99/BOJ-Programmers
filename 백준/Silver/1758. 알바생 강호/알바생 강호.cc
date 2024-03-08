#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n;
	cin >> n;
	vector<long long>t;

	for (int i = 0; i < n; i++)
	{
		int tip;
		cin >> tip;
		t.push_back(tip);
	}
	long long ans = 0;
	sort(t.begin(), t.end(), greater<long long>());

	for (int i = 1; i <= n; i++)
	{
		int res = 0;
		res = t[i - 1] - (i - 1);

		if (res > 0)
		{
			ans += res;
		}
		else
			ans += 0;
	}
	cout << ans;
}