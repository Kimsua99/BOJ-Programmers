#include <bits/stdc++.h>
using namespace std;

int N, M;

vector<int> A, B, answer;

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) 
	{
		int d; 
		cin >> d;
		A.push_back(d);
	}
	for (int i = 0; i < M; i++) 
	{
		int c; 
		cin >> c;
		B.push_back(c);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for (int i = 0; i < A.size(); i++)
	{
		int x = A[i];
		int left = 0, right = B.size() - 1;
		bool isIn = false;

		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (B[mid] == x) 
			{
				isIn = true;
				break;
			}
			if (x < B[mid]) 
				right = mid - 1;
			else if (x > B[mid]) 
				left = mid + 1;
		}
		if (!isIn) 
			answer.push_back(x);
	}
	cout << answer.size() << endl;

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
}
