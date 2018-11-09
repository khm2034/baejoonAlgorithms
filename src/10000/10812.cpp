#include<cstdio>
int a[101], N, M, b, e, m, t[101];
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) a[i] = i;
	while (M--) {
		scanf("%d%d%d", &b, &e, &m);
		for (int i = b; i < m; i++) t[i] = a[i];
		for (int i = m, j=b; i <= e; i++) a[j++] = a[i];
		for (int i = b,j=b+e-m+1; i < m; i++) a[j++] = t[i];
	}
	for (int i = 1; i <= N; i++) printf("%d ", a[i]);
	return 0;
}