#include <iostream>
using namespace std;

const int MX = 100005;
int dat[MX];
int head = 0, tail = 0;

void push(int x)//값을 넣고 테일을 하나 증가
{
	dat[tail++] = x;
}

void pop()//빼는 경우에 헤드를 하나 증가
{
	head++;
}

int front()
{
	return dat[head];
}

int back()
{
	return dat[tail - 1];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	while (n--)
	{
		string str;
		cin >> str;

		if (str == "push")
		{
			int val;
			cin >> val;
			push(val);
		}
		else if (str == "pop")
		{
			if (tail == head)//끝과 처음이 같으므로 반환할 값이 없기 때문에 -1 출력
				cout << -1 << '\n';
			else
			{
				cout << front() << '\n';
				pop();
			}
		}

		else if (str == "size")
		{
			cout << tail - head << '\n';
		}

		else if (str == "empty")
		{
			cout << (tail == head) << '\n';
		}

		else if (str == "front")
		{
			if (tail == head)
			{
				cout << -1 << '\n';
			}
			else
				cout << front() << '\n';
		}

		else//str == "back"
		{
			if (tail == head)
			{
				cout << -1 << '\n';
			}
			else
				cout << back() << '\n';
		}
	}
}