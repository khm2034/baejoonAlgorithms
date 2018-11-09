#include<cstdio>
int a[10], n, mx;
int main() {
	freopen("input.txt", "r", stdin);
	while (scanf("%1d", &n) != EOF) {
		a[n]++;
	}
	a[6] += a[9]+1;
	a[6] /= 2;
	for (int i = 0; i < 9; i++) mx = mx < a[i] ? a[i] : mx;
	printf("%d", mx);
	return 0;
}