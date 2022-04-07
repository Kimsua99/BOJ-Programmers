#include <iostream>
using namespace std;

int main()
{
	long long arr[91] = { 0,1, };//arr[90]의 값이 매우 크기 때문에 long long

	int n;

	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cout << arr[n];

	return 0;
}