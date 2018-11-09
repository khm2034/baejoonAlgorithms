#include<cstdio>
int N, M, a[101], i, j;
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) a[i] = i;
	while (M--) {
		scanf("%d%d", &i, &j);
		for (int k = i, l=j; k <= (j+i) / 2; k++,l--) {
			int c(a[k]); a[k] = a[l]; a[l] = c;
		}
	}
	for (int i = 1; i <= N; i++) printf("%d ", a[i]);
	return 0;
}