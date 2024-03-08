#include <bits/stdc++.h>
using namespace std;

bool flag = false;
string s = "";
int ans;
string st;

int main(void)
{
	cin >> s;

	for (int i = 0; i <= s.size(); i++)
	{
		if (s[i] == '-' || s[i] == '+' || i == s.size())
		{
			if (flag == true)//앞서 -가 있었을 경우
			{
				ans -= stoi(st);
				st = "";
			}
			else
			{
				ans += stoi(st);
				st = "";
			}
		}
		else
		{
			st += s[i];
		}
		if (s[i] == '-')
			flag = true;
	}
	cout << ans;
}