#include <bits/stdc++.h>
using namespace std;

unordered_set<string> s; //중복 허용이 안되는 집합같은 stl

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  while(n--)
  {
    string name, log;
    cin >> name >> log;
    if(log == "enter") //출근의 경우
        s.insert(name);//해당 이름 추가
    else s.erase(name);//퇴근의 경우 해당 이름 제거
  }
  vector<string> ans(s.begin(), s.end());//결과를 담을 벡터 배열
  sort(ans.begin(), ans.end(), greater<string>());//greater -> 역순 정렬
  for(auto x : ans) cout << x << '\n';
}