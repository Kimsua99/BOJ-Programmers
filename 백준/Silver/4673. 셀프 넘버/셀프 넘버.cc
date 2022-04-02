#include <iostream>
using namespace std;

/*생성자가 있는 수를 인덱스로 해서 그 값을 1로 주고
모두 계산하여 해당 인덱스의 값이 1이 아니면 셀프 넘버로 출력이 되도록 구현하면 됨.*/

int main()
{
	int n = 0;
	int	arr[10001];
	int non_self = 0;


	for (n = 1; n <= 10000; n++) 

	{
		if (n < 10) //한자리수->그 수 * 2가 다음 수임.
		{
			non_self = n + n;
			arr[non_self] = 1;
		}
		else if (n < 100) //두자리 수
		{
			non_self = n + (n / 10) + (n % 10);
			arr[non_self] = 1;
		}
		else if (n < 1000) //세자리 수
		{
			non_self = n + (n / 100) + ((n % 100) / 10) + ((n % 100) % 10);
			arr[non_self] = 1;
		}
		else if (n < 10000) //네자리 수
		{
			non_self = n + (n / 1000) + ((n % 1000) / 100) + (((n % 1000) % 100) / 10) + (((n % 1000) % 100) % 10);
			
			if (non_self <= 10000)
			{
				arr[non_self] = 1;
			}
		}
	}

	for (n = 1; n <= 10000; n++) 
	{
		if (arr[n] != 1)//배열의 값이 1이 아닌 인덱스 n을 출력
		{
			cout << n << "\n";
		}
	}
	return 0;
}