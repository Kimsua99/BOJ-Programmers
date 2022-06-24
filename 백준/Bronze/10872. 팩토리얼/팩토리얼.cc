#include <bits/stdc++.h>
using namespace std;

int factorial(int n) 
{
	if (n == 0)
		return 1;
	if (n == 1)
		return n;
	return n * factorial(n - 1);

}

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	cout << factorial(n);
}