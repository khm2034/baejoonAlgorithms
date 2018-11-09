#include<cstdio>

bool a[1001] = { 0,1 };
int N, arr[101], cnt;
int main()
{
	for (int i = 2; i <= 31; i++)
		for (int j = 2; j <= 1000 / i; j++)
			a[i*j] = true;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < N; i++)
		if (!a[arr[i]])
			cnt++;
	printf("%d\n", cnt);
}