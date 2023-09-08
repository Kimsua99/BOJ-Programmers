#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str, str2;
    cin >> str >> str2;

    string removedStr = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] - '0' >= 0 && str[i] - '0' <= 9) continue;
        removedStr.push_back(str[i]);
    }

    if (removedStr.find(str2) == string::npos) {  //없으면
        cout << 0;
    }
    else cout << 1;


    return 0;
}