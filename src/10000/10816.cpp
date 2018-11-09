#include<cstdio>
#define b 10000000
int a[2*b+1], N, t;
int main() {
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &t);
		a[t + b]++;
	}
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &t);
		printf("%d ", a[t + b]);
	}
	return 0;
}