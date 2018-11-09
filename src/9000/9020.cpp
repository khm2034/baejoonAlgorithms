#include<cstdio>
int t, p[10001], a;
int main() {
	for (int i = 2; i*i <= 10000; i++) {
		for (int j = i*2; j <= 10000; j += i) p[j] = 1;
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &a);
		int le, ri, d = 1e9;
		for (int i = a / 2; i >= 2; i--) {
			if (!p[i] && !p[a - i] && a-i-i < d) {
				le = i, ri = a - i;
				break;
			}
		}
		for (int i = a / 2; i <= 2; i++) {
			if (!p[i] && !p[a - i] && i+i-a < d) {
				le = a - i, ri = i;
				break;
			}
		}
		printf("%d %d\n", le, ri);
	}
	return 0;
}