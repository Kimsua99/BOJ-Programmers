#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[100001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;

	int st, en, mid, ans;

	st = 0, en = arr[n - 1];

	while (st <= en)
	{
		int sum = 0;
		mid = (st + en) / 2;
		for (int i = 0; i < n; i++)
		{
			sum += min(arr[i], mid);
		}
		if (sum > m)
		{
			en = mid - 1;
		}
		else if (sum <= m)
		{
			ans = mid;
			st = mid + 1;
		}
	}

	cout << ans;
}