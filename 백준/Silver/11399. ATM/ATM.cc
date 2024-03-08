#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n;
	int time[1001];
	vector<int> v;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> time[i];
	}

	sort(time, time + n);

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		count += time[i];
		v.push_back(count);
	}

	int ans = 0;

	for (int i = 0; i < v.size(); i++)
		ans += v[i];

	cout << ans;
}