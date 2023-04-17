#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  string s, p;
  unordered_map<string, string> umap;//키에 대응되는 값 넣는 집합

  cin >> N >> M;//저장된 사이트 주소 개수, 비밀번호 찾으려는 사이트 주소 개수
  while (N--) 
  {
    cin >> s >> p;//사이트 주소, 비밀번호
    umap[s] = p;//키와 값으로 주소 개수만큼 집합 채움
  }
  while (M--) //비밀번호 찾으려는 사이트 주소 개수만큼 돌아
  {
    cin >> s;
    cout << umap[s] << '\n';//주소에 해당되는 비밀번호 출력
  }
}