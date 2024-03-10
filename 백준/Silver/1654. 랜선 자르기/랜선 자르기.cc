#include <bits/stdc++.h>
using namespace std;

unsigned int ans;
unsigned int N, K;
unsigned int arr[10000];

int main()
{
	cin >> K >> N;

	unsigned int mnum = 0;

	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
		mnum = max(mnum, arr[i]);
	}

	unsigned int st = 1, en = mnum, mid;

	while (st <= en)
	{
		mid = (st + en) / 2;

		unsigned int cnt = 0;

		for (int i = 0; i < K; i++)
			cnt += arr[i] / mid;

		if (cnt >= N)
		{
			st = mid + 1;
			ans = max(ans, mid);
		}
		else
			en = mid - 1;
	}

	cout << ans << '\n';
}