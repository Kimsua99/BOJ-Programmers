#include <queue> 
#include <iostream>
#include <algorithm>
using namespace std; 
typedef long long ll; 
priority_queue<ll, vector<ll>, greater<ll>> q;

int main() {
	int n; cin >> n; 
	int m; cin >> m;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a; 
		q.push(a); 
	}
	while (m--) {
		ll a, b; 
		a = q.top(); 
		q.pop(); 
		b = q.top(); 
		q.pop(); 
		q.push(a + b); 
		q.push(a + b); 
	}
	ll sum = 0; 
	while (!q.empty()) {

		sum += q.top(); 
		q.pop(); 
	}
	cout << sum; 
}