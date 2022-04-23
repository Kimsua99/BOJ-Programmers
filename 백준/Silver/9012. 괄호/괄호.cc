#include <iostream>
#include <stack>
using namespace std;

int T;
string str;
stack<char> st;

int main(void)
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == '(')//왼쪽 괄호이면 스택에 푸쉬
			{
				st.push(str[j]);
			}
			if (str[j] == ')')//오른쪽 괄호일 경우에
			{
				if (st.empty())//스택이 비어있으면 
				{
					st.push(str[j]);//짝이 맞지 않으므로 비어있지 않은 상태를 유지하기 위해 푸쉬
					break;
				}
				else
					st.pop();//비어있지 않으면 무조건 처음은 (라서 짝이 맞을테니까 팝을 해서 스택에서 빼냄.
			}
		}
		if (st.empty())//모두 짝이 맞아야지 빼내는 것이므로 yes 출력
			cout << "YES" << '\n';
		else
		{
			cout << "NO" << '\n';//짝이 맞지 않는 경우이므로 no 출력
			while (!st.empty())//한바퀴가 돌았으므로 스택을 비워줘야 하므로 스택이 비어있지 않은 경우에 팝해서 내용물을 빼냄.
				st.pop();
		}
	}
}