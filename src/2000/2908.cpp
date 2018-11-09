#include<cstdio>
int main() {
	int ar[2];
	for (int i = 0, a, b, c; i < 2; i++) {
		scanf(" %1d%1d%1d", &a, &b, &c);
		ar[i] = c * 100 + b * 10 + a;
	}
	printf("%d", ar[0] > ar[1] ? ar[0] : ar[1]);
}