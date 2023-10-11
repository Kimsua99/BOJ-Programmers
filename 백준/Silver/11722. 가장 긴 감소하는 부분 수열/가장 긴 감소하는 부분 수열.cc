//DP
#include <bits/stdc++.h>
using namespace std;

int n;
int d[1001];
int a[1001];
int sum;

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		d[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] < a[j])
				d[i] = max(d[i], d[j] + 1);
		}
		sum = max(sum, d[i]);
	}

	cout << sum;
}