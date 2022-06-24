#include <bits/stdc++.h>
using namespace std;

int z(int n, int r, int c) 
{
	if (n == 0) //base condition
		return 0;

	int half = 1 << (n - 1);//비트 연산자, half = 2의 n-1승으로 한변 길이의 절반임.

	if (r < half && c < half) return z(n - 1, r, c);//(r,c)가 1번 사각형일 경우
	if (r < half && c >= half) return half * half + z(n - 1, r, c - half);//(r,c)가 2번 사각형일 경우
	if (r >= half && c < half) return 2 * half * half + z(n - 1, r - half, c);//(r,c)가 3번 사각형일 경우
	return 3 * half * half + z(n - 1, r - half, c - half);//(r,c)가 4번 사각형일 경우
}

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r, c;
	cin >> n >> r >> c;
	cout << z(n, r, c);
}