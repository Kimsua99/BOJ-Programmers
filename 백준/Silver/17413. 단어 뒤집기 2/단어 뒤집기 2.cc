#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    getline(cin, s);
    int n = s.size();

    for(int i=0;i<n;){
        if(s[i] == ' '){
            i++;
            continue;
        }
        if(s[i] == '<'){
            int j=i;
            while(j<n&&s[j]!='>') j++;
            i = j + 1;
        }
        int j=i;
        while(j<n&&s[j]!=' '&&s[j] != '<') j++;
        reverse(s.begin() + i, s.begin() + j);
        i = j;
    }
    cout << s;

    return 0;
}