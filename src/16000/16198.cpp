#include<cstdio>
int n, a[11], v[11], mx;
void func(int c, int w) {
	if (c == n - 2) {
		mx = mx < w ? w : mx;
		return;
	}
	for (int i = 1, j, k; i < n; i++) {
		if (v[i]) continue;
		v[i] = 1;
		for (j = i - 1; j > 0; j--) if (!v[j]) break;
		for (k = i + 1; k < n - 1; k++) if (!v[k]) break;
		func(c + 1, w + a[j] * a[k]);
		v[i] = 0;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	func(0, 0);
	printf("%d", mx);
	return 0;
}