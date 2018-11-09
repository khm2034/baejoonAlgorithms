#include<cstdio>
int e, s, m;
int main() {
	scanf("%d%d%d", &e, &s, &m);
	for (int i = 1, a, b, c; i < 16 * 29 * 20; i++) {
		a = (i-1) % 15 +1;
		b = (i-1) % 28 +1;
		c = (i-1) % 19 +1;
		if (a == e && b == s && c == m) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}