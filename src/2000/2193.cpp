#include<cstdio>
int N;
long long dp[91][2] = { 0, 0, 0, 1 };
int main() {
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	printf("%lld\n", dp[N][0] + dp[N][1]);
	return 0;
}