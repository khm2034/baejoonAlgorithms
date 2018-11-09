#include<cstdio>
#define base 10000000
int N, M;
bool a[2*base +2];
int main() {
	scanf("%d", &N);
	for (int i = 0, t; i < N; i++) {
		scanf("%d", &t);
		a[t + base] = 1;
	}
	scanf("%d", &M);
	for (int i = 0,t; i < M; i++) {
		scanf("%d", &t);
		if (a[t + base]) printf("1 ");
		else printf("0 ");
	}
	return 0;
}