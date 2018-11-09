#include<cstdio>
int N, K, a[10], c;
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	for (int i = N - 1; i >= 0; i--) {
		c += K / a[i];
		K %= a[i];
	}
	printf("%d", c);
	return 0;
}