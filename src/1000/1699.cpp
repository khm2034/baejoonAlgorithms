#include<cstdio>
#include<cmath>
int N, dp[100001] = { 0, 1 };
inline int min(int x, int y) {
	return x > y ? y: x;
}
int main() {
	scanf("%d", &N);
	for (int i = 2, mi=1e9; i <= N; i++, mi=1e9) {
		for (int j = sqrt(i); j >= 1; j--) {
			mi = min(mi, dp[i - (j*j)]+1);
		}
		dp[i] = mi;
	}
	printf("%d\n", dp[N]);
	return 0;
}