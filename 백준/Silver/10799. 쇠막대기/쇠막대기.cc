#include<bits/stdc++.h>
using namespace std;

string s;
int ans = 0;

int main() 
{
    cin >> s;

    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(') 
            st.push(s[i]);

        else 
        { 
            if (s[i - 1] == '(')
            { 
                st.pop();
                ans += st.size();
            }
            else 
            { 
                st.pop();
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}