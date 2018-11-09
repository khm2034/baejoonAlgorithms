#include<cstdio>
int a[51], T, K;
bool func(int c, int s) {
	if (c == 3) {
		if (s != K) return false;
		return true;
	}
	for (int i = 1; i <= 50; i++) {
		if (s + a[i] > K) return false;
		if (func(c + 1, s + a[i])) return true;
	}
	return false;
}
int main() {
	for (int i = 1; i < 50; i++) a[i] = i * (i + 1) / 2;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &K);
		if (func(0, 0)) printf("1\n");
		else printf("0\n");
	}
	return 0;
}