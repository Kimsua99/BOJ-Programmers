#include <bits/stdc++.h>
using namespace std;

void hanoi(int a, int b, int n) 
{
    if (n == 1) 
    {
        cout << a << ' ' << b << '\n';//base condition
        return;
    }
    hanoi(a, 6 - a - b, n - 1);//1번 기둥에서 2번 기둥으로 n-1개의 원판 이동
    cout << a << ' ' << b << '\n';
    hanoi(6 - a - b, b, n - 1);//2번 기둥에서 3번 기둥으로 n-1개의 원판 이동
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    cout << (1 << k) - 1 << '\n'; //비트 연산자 -> 1을 비트 기준 왼쪽으로 k칸 밀기 때문에 2의 k승 - 1임.
    hanoi(1, 3, k);
}