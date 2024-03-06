#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;

	cin >> n;
	priority_queue<int> pq;
	vector<int>v;
	pq.push(0);

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		if (x == 0)
		{
			if (pq.empty())
			{
				v.push_back(0);
			}
			else
			{
				v.push_back(pq.top());
				pq.pop();
			}
		}
		else
		{
			pq.push(x);
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
}