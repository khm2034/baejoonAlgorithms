#include<cstdio>
int T, m, n, x, y, ret;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d", &m, &n, &x, &y);
		ret = x;
		while (ret <= m * n) {
			if (ret%n == y%n) break;
			ret += m;
		}
		if (ret > m*n) printf("-1\n");
		else printf("%d\n", ret);
	}
	return 0;
}