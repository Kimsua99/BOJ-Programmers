#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll POW(ll a, ll b, ll m) 
{
	if (b == 1) return a % m;//base condition

	ll val = POW(a, b / 2, m);//재귀 -> a를 b번 곱한 수를 m으로 나누므로 b/2를 곱한 수에 대한 값도 구할 수 있다. 
	val = val * val % m;

	if (b % 2 == 0) //b가 짝수인 경우
		return val;
	return val * a % m;//b가 홀수인 경우에 b를 짝수로 만들어주고 a를 곱해준다.
}

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a, b, c;
	cin >> a >> b >> c;
	cout << POW(a, b, c);
}