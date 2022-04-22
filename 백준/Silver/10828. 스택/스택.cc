#include <iostream>
using namespace std;

const int MX = 100005;
int dat[MX];
int pos = 0;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  string s;
  int x;
  for (int i = 0; i < N; i++) {
    cin >> s;
    if (s == "push") {
      cin >> x;
      dat[pos++] = x;
    } else if (s == "pop") {
      if (!pos)
        cout << -1 << '\n';
      else {
        pos--;
        cout << dat[pos] << '\n';
      }
    } else if (s == "size") {
      cout << pos << '\n';
    } else if (s == "empty") {
      if (pos)
        cout << 0 << '\n';
      else
        cout << 1 << '\n';
    } else if (s == "top") {
      if (!pos)
        cout << -1 << '\n';
      else
        cout << dat[pos - 1] << '\n';
    }
  }
}