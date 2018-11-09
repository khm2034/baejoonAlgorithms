#include<cstdio>
int v[201], N, t;
int main() {
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &t);
		v[t + 100]++;
	}
	scanf("%d", &N);
	printf("%d", v[N + 100]);
	return 0;
}