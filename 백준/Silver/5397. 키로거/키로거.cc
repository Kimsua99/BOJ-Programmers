#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;

    cin >> n;//테스트케이스 수

    for (int i = 0; i < n; i++) 
    {
        list<char> L = {}; // 입력한 문자열
        string s;
        auto p = L.begin();//p = 리스트 제일 앞

        cin >> s;//문자열 입력받음
        for (auto c : s)  //문자열 돌면서 반복
        {
            if (c == '<') // < : 왼쪽 화살표 입력
            {
                if (p != L.begin()) p--; //p가 리스트 제일 앞이 아니면 p를 왼쪽으로 한칸 이동
            }
            else if (c == '>') 
            {
                if (p != L.end()) p++; // p가 리스트 맨 뒤가 아니면 p를 오른쪽으로 한칸 이동
            }
            else if (c == '-')  //백스페이스 입력 경우
            {
                if (p != L.begin()) //p가 제일 처음이 아니면
                {
                    p--; //p를 왼쪽으로 한칸 이동하고
                    p = L.erase(p);//p를 지움
                }
            }
            else
                L.insert(p, c);//나머지 -> 문자 입력 경우 -> 해당 문자를 p위치에 삽입
        }
        for (auto c : L) cout << c; //리스트 출력
        cout << '\n';
    }
}