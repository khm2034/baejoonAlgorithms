#include<cstdio>
int N, M, a[101], i, j;
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) a[i] = i;
	while (M--) {
		scanf("%d%d", &i, &j);
		int c(a[i]); a[i] = a[j]; a[j] = c;
	}
	for (int i = 1; i <= N; i++) printf("%d ", a[i]);
	return 0;
}