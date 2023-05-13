#include <iostream>
#include<string>
#include <stack>
#include <algorithm>
using namespace std;

int solution(string s)
{
    int answer = 0;

    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (!st.empty() && s[i] == st.top())
        {
            st.pop();
        }
        else
            st.push(s[i]);

    }

    if (!st.empty())
        answer = 0;
    else
        answer = 1;

    return answer;
}