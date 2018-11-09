#include<cstdio>
int N, idx, a[1<<19], b[1<<19];
int main() {
	scanf("%d", &N);
	for (int i = 1, t; i <= N; i++) {
		scanf("%d", &t);
		for (int j = idx - 1; j >= 0 && t > b[j]; j--, idx--);
		if (!idx) printf("0 ");
		else printf("%d ", a[idx-1]);
		a[idx] = i, b[idx++] = t;
	}
}