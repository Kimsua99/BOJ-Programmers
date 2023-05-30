#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) 
{
    int answer = 0;

    for (int i = 0; i < s.length(); ++i) 
    {
        stack<char> st;
        
        bool flag = false;//닫힌 괄호만 올 경우를 대비해서 열린 괄호 하나라도 있으면 TRUE
        
        for (int i = 0; i < s.length(); ++i) 
        {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(') //시작 괄호이므로 푸시해줌.
            {
                flag = true;
                st.push(s[i]);
            }
            
            else //이미 스택의 탑에 열린 괄호가 있는 상태일 경우 닫힌 괄호가 맞는 것이 오면 POP해서 제거
            {
                if (s[i] == ']' && st.top() == '[')
                    st.pop();
                if (s[i] == '}' && st.top() == '{')
                    st.pop();
                if (s[i] == ')' && st.top() == '(')
                    st.pop();
            }
        }
        
        if (st.empty() && flag) answer++; //비어있을 경우 짝이 다 지어져서 나간 것이므로 결과++

        /* 괄호 회전 과정 */ //이 과정은 0일 경우에는 발생 안하다가 1부터 단계별로 한번씩 작동함
        char ch = s.front();//가장 앞을 빼두고, 가장 앞 지운 후 맨 뒤에 가장 앞 원소 푸시해줌.
        s.erase(s.begin());
        s.push_back(ch);
    }
    return answer;
}