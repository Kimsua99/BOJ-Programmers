#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  int t;
  cin >> t;
  while(t--)
  {
    int k;
    cin >> k;
    multiset<int> ms;//이진 검색 트리 -> 원소의 중복 허용 되는 집합
    while(k--)
    {
      char com;
      cin >> com;
      if(com == 'D')//삭제
      {
        int q;
        cin >> q;
        if(ms.empty()) continue;//비었으면 다음 반복 실행
        if(q == 1) //최댓값 삭제의 경우
            ms.erase(prev(ms.end()));//end가 끝 + 1이므로 end의 prev는 제일 끝 원소 값에 해당됨
        else//최솟값 삭제의 경우 
            ms.erase(ms.begin());//제일 처음 원소 삭제
      }
      else//삽입
      {
        int q;
        cin >> q;
        ms.insert(q);
      }
    }
    if(ms.empty()) //비었을 경우
        cout << "EMPTY\n";
    else
    {
      cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';//최댓값, 최솟값 순서로 출력
    }
  }
}
