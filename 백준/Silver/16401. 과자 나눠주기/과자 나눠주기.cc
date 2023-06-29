#include <bits/stdc++.h>
using namespace std;

int M, N;
vector<int> L;

int main()
{
	cin >> M >> N;
	for (int i = 0; i < N; i++) 
	{
		int l;
		cin >> l;
		L.push_back(l);
	}

	int st = 1, en = *max_element(L.begin(), L.end());

	int snack = 0;

	while (st <= en)
	{
		int mid = (st + en) / 2; 
		int count = 0;

		for (int i = 0; i < N; i++) 
			count += L[i] / mid;

		if (count >= M)
		{ 
			st = mid + 1;
			snack = mid;
		}
		else if (count < M) 
			en = mid - 1;
	}
	cout << snack << "\n";
}