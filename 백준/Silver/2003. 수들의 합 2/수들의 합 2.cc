#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[10001];
int cnt, st, en, sum;

int main() 
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) 
	{
		cin >> A[i];
	}

	while (en <= N)
	{
		if (sum < M) 
		{
			sum += A[en];
			en++;
		}
		if (sum >= M) 
		{
			if (sum == M)
				cnt++;

			sum -= A[st];
			st++;
		}
	}
	cout << cnt;
}