#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; //n은 큐의 크기, m은 뽑으려는 수의 개수

    cin >> n >> m;

    deque<int> DQ;

    for (int i = 1; i <= n; i++) 
        DQ.push_back(i);//큐에 1부터 숫자 채움. 

    int ans = 0;//연산 진행한 카운트 값

    while (m--) 
    {
        int t;
        cin >> t;//뽑으려는 숫자

        int idx = find(DQ.begin(), DQ.end(), t) - DQ.begin(); // idx : t가 있는 위치 -> 숫자 2면 인덱스는 1임.

        while (DQ.front() != t) //덱의 맨 앞 원소가 찾으려는 숫자 아니면 연산 수행
        {
            if (idx < DQ.size() - idx) //큐 크기에서 가운데보다 찾으려는 숫자가 왼쪽에 있으면
            {
                DQ.push_back(DQ.front());//맨 앞의 숫자를 맨뒤로 넘김
                DQ.pop_front();
            }
            else //가운데보다 찾으려는 숫자가 오른쪽에 있으면 뒤에서 찾는게 빠르므로
            {
                DQ.push_front(DQ.back());//맨뒤의 숫자를 맨 앞으로 넘김
                DQ.pop_back();
            }
            ans++; //연산 진행했으므로 카운트 값 증가
        }
        DQ.pop_front();// 덱 맨 앞에 원소가 찾으려는 숫자면 앞에꺼 바로 꺼냄.
    }
    cout << ans;//연산 진행 횟수 출력
}