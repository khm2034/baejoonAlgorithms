#include<cstdio>
int a[101], N, M, i,j,k;
int main() {
	scanf("%d%d", &N, &M);
	while (M--) {
		scanf("%d%d%d", &i, &j, &k);
		for (int t = i; t <= j; t++) a[t] = k;
	}
	for (int i = 1; i <= N; i++) printf("%d ", a[i]);
	return 0;
}