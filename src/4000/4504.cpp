#include<cstdio>
int n, a;
int main() {
	scanf("%d", &n);
	while (1) {
		scanf("%d", &a);
		if (!a) break;
		if (a%n) printf("%d is NOT a multiple of %d.\n", a, n);
		else printf("%d is a multiple of %d.\n", a, n);
	}
	return 0;
}