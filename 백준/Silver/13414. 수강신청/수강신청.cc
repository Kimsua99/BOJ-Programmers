#include <bits/stdc++.h>
using namespace std;
int k, l;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	map<string, int>m;
	vector<pair<int, string>>v;

	int k, L; cin >> k >> L;
	for (int i = 0; i < L; i++) {
		string number; cin >> number;
		m[number] = i + 1;
	}

	for (auto i = m.begin(); i != m.end(); i++) {
		string a = i->first;
		int b = i->second;
		v.push_back({ b,a });
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < min(k, (int)v.size()); i++) {	//출력
		cout << v[i].second << "\n";
	}
}