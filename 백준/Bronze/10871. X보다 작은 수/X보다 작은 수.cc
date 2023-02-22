#include <stdio.h>
int main() {
	int n, m, x;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		if (x < m)
		{
			printf("%d ", x);
		}
	}
	return 0;
}
