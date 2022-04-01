#include <stdio.h>

int input, result;

int Hansu(int n)
{
	int i;
	int n1, n2, n3;
	int count = 0;

	if (n < 100)//1,10의 자리 수는 계산하지 않아도 한수이므로 그대로 출력함.
	{
		return n;
	}
	else //백의 자리부터 한수 계산해야 함.
	{
		for (i = 100; i <= n; i++) //각 자리 수를 구함.
		{
			n1 = i / 100; //백의 자리 수
			n2 = (i % 100) / 10; //십의 자리 수
			n3 = (i % 100) % 10; //일의 자리 수

			if ((n1 - n2) == (n2 - n3))//연속된 두 개의 수의 차이가 일정하다면
				count++; //카운트를 하나씩 증가
		}
		return (99 + count);//99까지는 두자리 수 이므로 모두 한수라서 99에 카운트 값을 더해 한수 몇개인지 측정 가능.
	}
}
int main()
{
	scanf_s("%d", &input);
	result = Hansu(input);
	printf("%d", result);
}
