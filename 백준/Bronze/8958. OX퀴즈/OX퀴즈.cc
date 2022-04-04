#include <iostream>
#include <string>
using namespace std;

int main() 
{
	int n;
	string str;

	cin >> n;//테스트 케이스의 개수

	for (int i = 0; i < n; i++) 
	{
		cin >> str;//문장 입력받음

		int sum = 0;
		int count = 0;

		for (int j = 0; j < str.length(); j++) //문장 내 철자 길이만큼 돌아
		{
			if (str[j] == 'O')//O가 있다면
			{
				count++;//카운트 증가
			}
			else
			{
				count = 0;//0가 없다면 카운트 0으로 초기화
			}

			sum += count;//한 문장 내의 카운트 값 계산
		}
		cout << sum << '\n';// 카운트 값 출력
	}
}