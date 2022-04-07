#include <iostream>

using namespace std;

int main() 
{
	int n;
	int cnt = 0;
	string str;

	cin >> n;

	for (int i = 0; i < n; i++) 
	{
		cin >> str;

		bool checky = true;

		for (int j = 0; j < str.length(); j++) 
		{
			for (int k = 0; k < j; k++) 
			{
				if (str[j] != str[j - 1] && str[j] == str[k]) 
				{
					checky = false;
					break;
				}
			}
		}
		if (checky == true) cnt++;
	}

	cout << cnt;

	return 0;
}