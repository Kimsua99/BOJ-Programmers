#include <bits/stdc++.h>
using namespace std;

string s;
int arr[26];

int cnt;
int idx;

int ans = 0;
char c = 'n';

int main() 
{
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] < 97) 
			arr[s[i] - 65]++; //대문자
		else
			arr[s[i] - 97]++; //소문자
	}

	for (int i = 0; i < 26; i++)
	{
		if (arr[i] > cnt)
		{
			cnt = arr[i];
			idx = i;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (cnt == arr[i])
		{
			ans++;
		}
	}
	if (ans > 1)
		cout << '?';
	else
		cout << (char)(idx + 65);
}

