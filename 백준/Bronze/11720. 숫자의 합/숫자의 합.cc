#include <iostream>
using namespace std;

int main()
{
	int n;
	int sum = 0;
	char arr[100];

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		sum += arr[i] - '0';//char형은 아스키코드 값 더해지므로 '0'을 빼야 숫자 값이 됨.
	}
	cout << sum;
}