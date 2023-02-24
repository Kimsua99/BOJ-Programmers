#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string init;
    cin >> init;

    list<char> L;
    for (auto c : init) 
        L.push_back(c);//문장을 다 돌면서 리스트에 문자 삽입함.

    auto cursor = L.end();//커서는 문장 맨 끝으로 이동
    int q;
    cin >> q;

    while (q--) { //q번 돌아
        char op;
        cin >> op; //문자 입력

        if (op == 'P') //p면 -> $라는 문자를 커서 왼쪽에 삽입함
        {
            char add;
            cin >> add; // add라는 문자를 커서 왼쪽에 삽입. 
            L.insert(cursor, add);
        }
        else if (op == 'L')
        {
            if (cursor != L.begin()) cursor--; //l이면 -> 커서가 맨 왼쪽이 아니면 왼쪽으로 한칸 이동하므로 --
        }
        else if (op == 'D') 
        {
            if (cursor != L.end()) cursor++; // d이면 -> 커서가 리스트 맨 오른쪽이 아니면 오른쪽으로 한칸 이동하므로 ++
        }
        else 
        { // 'B'
            if (cursor != L.begin()) { // b이면 -> 커서가 맨 왼쪽 아니면 커서 왼쪽으로 한칸 이동하고 이동된 커서의 오른쪽에 있는 문자를 삭제함.
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }
    for (auto c : L) cout << c; //리스트 다 돌면서 하나씩 출력
}