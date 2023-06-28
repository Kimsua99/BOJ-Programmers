#include <bits/stdc++.h>
using namespace std;

int n;
int d[1000005];
vector<int> v;
vector<int> u;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
		v.push_back(d[i]);
	}

	sort(v.begin(), v.end());


	for (int i = 0; i < n; i++)
	{
		if (i == 0 || v[i - 1] != v[i])
			u.push_back(v[i]);
	}

	for (int i = 0; i < n; i++)
	{
		cout << lower_bound(u.begin(), u.end(), d[i]) - u.begin() << ' ';
	}


}
