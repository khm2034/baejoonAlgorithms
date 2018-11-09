#include<cstdio>
int N, K, i;
int main() {
	scanf("%d%d", &N, &K);
	for (i = 1; K && i <= N; i++) {
		if (N%i) continue;
		K--;
	}
	printf("%d", K > 0 ? 0 : i - 1);
	return 0;
}