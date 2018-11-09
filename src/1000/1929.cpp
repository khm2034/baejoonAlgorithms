#include<cstdio>
int N, M;
bool arr[1000001] = { false,true };
int main()
{
	for (int i = 2; i <= 1e3; i++)
		for (int j = 2; j <= 1e6 / i; j++)
			arr[i*j] = true;
	scanf("%d%d", &N, &M);
	for (int i = N; i <= M; i++)
		if (!arr[i]) printf("%d\n", i);
	return 0;
}