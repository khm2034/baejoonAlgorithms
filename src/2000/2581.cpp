#include<cstdio>
int N, M, sum, mi;
bool arr[10001] = { 0, 1 };
int main()
{
	for (int i = 2; i <= 1e2; i++)
		for (int j = 2; j <= 1e4 / i; j++)
			arr[i*j] = true;
	scanf("%d%d", &N, &M);
	for (int i = M; i >= N; i--)
		if (!arr[i])
			sum += i, mi = i;
	if (!sum)	printf("-1\n");
	else printf("%d\n%d\n", sum, mi);
	return 0;
}