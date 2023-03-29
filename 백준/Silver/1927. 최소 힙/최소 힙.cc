#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;//연산의 개수
  unsigned int t;//t는 양수와 0만 표현이 가능함.
  priority_queue<unsigned int, vector<unsigned int>, greater<>> pq;
//기존 최대힙의 3번째 인자에 greater를 넣어 최소힙으로 전환
  cin >> N;
  for (int i = 0; i < N; i++) //n번만큼 반복
  {
    cin >> t; //t가 자연수일 경우 큐에 넣음
    if (t)
      pq.push(t);
    else //0일 경우 
    {
      if (pq.empty())//큐가 비었을 경우
        cout << "0\n";//0 출력하고 끝
      else //안 비었을 경우
      {
        cout << pq.top() << '\n';//배열에서 가장 작은 값 = 루트 값 출력
        pq.pop();//제거
      }
    }
  }
}