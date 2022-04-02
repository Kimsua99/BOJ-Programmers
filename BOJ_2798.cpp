#include <stdio.h>

int main()
{
	int n, m;
	int arr[100];

	int result = 0;
	int sum = 0;

	scanf_s("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				sum = arr[i] + arr[j] + arr[k];

				if (sum <= m && sum > result)
				{
					result = sum;
				}
			}
		}
	}

	printf("%d", result);

	return 0;

}