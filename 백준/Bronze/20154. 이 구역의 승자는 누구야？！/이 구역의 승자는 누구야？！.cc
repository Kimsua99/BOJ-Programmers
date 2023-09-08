#include <bits/stdc++.h>
using namespace std;

int alpha[26] = { 3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1 };
string s;

int main()
{
	cin >> s;

	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		sum += alpha[s[i] - 'A'];
		if (sum > 9)
			sum %= 10;
	}
	if (sum % 2 == 1)
		cout << "I'm a winner!\n";
	else
		cout << "You're the winner?\n";

	return 0;
}