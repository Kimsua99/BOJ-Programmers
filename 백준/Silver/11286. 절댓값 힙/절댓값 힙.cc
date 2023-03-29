#include <bits/stdc++.h>
using namespace std;

class cmp //비교를 위해 클래스 선언
{
  public:
  bool operator() (int a, int b) 
  {
    if(abs(a) != abs(b)) //절댓값이 다른 경우
        return abs(a) > abs(b);//절댓값이 앞의 수가 뒤의 수보다 크면 true 반환
    return a > 0 && b < 0;//절댓값이 같은 경우 1. 두 수가 다름 2. 앞이 양수고 뒤가 음수임 -> true 반환
  }//비교 함수의 두 값이 같은 값이면 무조건 false 반환해야 함.
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  priority_queue<int, vector<int>, cmp> pq;//최대힙
    
  int n;
  cin >> n;
  while(n--)
  {
    int x;
    cin >> x;
    if(x == 0)//값이 0일 경우
    {
      if(pq.empty())//큐가 비었을 경우
          cout << "0\n";//0과 함께 끝
      else//안 비었을 경우
      {
        cout << pq.top() << '\n';//top하고 반환
        pq.pop();//제거
      }
    }
    else pq.push(x);//0이 아니면 무조건 push
  }
}