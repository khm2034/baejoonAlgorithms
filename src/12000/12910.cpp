#include<cstdio>
int a[51], N, ret;
int main() {
	scanf("%d", &N);
	for (int i = 0, t; i < N; i++) {
		scanf("%d", &t);
		a[t]++;
	}
	for (int i = 1, t=a[i]; a[i] && i <= N; i++, t *= a[i]) ret += t;
	printf("%d", ret);
	return 0;
}