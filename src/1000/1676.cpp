#include<cstdio>
int n, c;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i % 5 == 0) {
			int t = i;
			while (t%5 == 0) {
				t /= 5;
				c++;
			}
		}
	}
	printf("%d", c);
	return 0;
}