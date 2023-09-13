#include <bits/stdc++.h>
using namespace std;

int n;
int num;

int main()
{
	int minValue = 1000001;
	int maxValue = -1000001;

	int N;
	cin >> N;

	int inputValue;
	for (int i = 0; i < N; i++) 
	{
		cin >> inputValue;

		if (inputValue < minValue) 
		{
			minValue = inputValue;
		}
		if (inputValue > maxValue) 
		{
			maxValue = inputValue;
		}
	}

	cout << minValue << " " << maxValue;
	return 0;
}