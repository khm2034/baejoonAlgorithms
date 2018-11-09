#include<cstdio>
int T, N, dp[12] = { 1,1,2 };
int main() {
	scanf("%d", &T);
	for (int i = 3; i < 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	while (T--) {
		scanf("%d", &N);
		printf("%d\n", dp[N]);
	}
	return 0;
}