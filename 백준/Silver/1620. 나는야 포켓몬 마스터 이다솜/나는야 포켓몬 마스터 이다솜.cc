#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> s2i;//포켓몬 숫자 담을 집합
string i2s[100005];//포켓몬 이름 담을 배열

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  int n, m;
  cin >> n >> m;//도감 등록 포켓몬 개수, 맞춰야 하는 개수
  for(int i = 1; i <= n; i++)
  {
    cin >> i2s[i];//도감에 순차적으로 등록
    s2i[i2s[i]] = i;
  }
  while(m--)
  {
    string query;
    cin >> query;
      
    if(isdigit(query[0]))//숫자일 경우 -> 문자로 대답
      cout << i2s[stoi(query)] << '\n';
    else//문자일 경우 -> 숫자로 대답
      cout << s2i[query] << '\n';
  }
}
