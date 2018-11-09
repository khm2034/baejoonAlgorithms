#include<cstdio>
int d, c[10];
int main() {
	scanf("%d", &d);
	for (int i = 0, t; i < 5; i++) {
		scanf("%d", &t);
		c[t]++;
	}
	printf("%d", c[d]);
	return 0;
}