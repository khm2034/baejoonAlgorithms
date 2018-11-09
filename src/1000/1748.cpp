#include<cstdio>
int N;
long long int ret;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i *=10)
		ret += N - i + 1;
	printf("%d\n", ret);
	return 0;
}
