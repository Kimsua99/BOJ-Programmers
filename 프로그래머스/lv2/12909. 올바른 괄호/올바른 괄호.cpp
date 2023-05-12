#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack <int> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
                st.pop();
            else
                st.push(s[i]);
        }
    }
    if (st.empty() == false)
        answer = false;
    else
        answer = true;

    return answer;
}