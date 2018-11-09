#include<cstdio>
int N;
int main() {
	scanf("%d", &N);
	for (int i = 1, k=i; i <= N; i++, k=i) {
		for (int j = i; j > 0; j /= 10) k += j % 10;
		if (k == N) {
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
	return 0;
}