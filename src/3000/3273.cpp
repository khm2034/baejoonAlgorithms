#include<cstdio>
int N, a[2000001], X, c;
int main() {
	scanf("%d", &N);
	for (int i = 0, t; i < N; i++) {
		scanf("%d", &t);
		a[t]++;
	}
	scanf("%d", &X);
	for (int i = 1; i * 2 < X; i++) c += (a[i] * a[X - i]);
	printf("%d", c);
	return 0;
}