#include<cstdio>
int N, dp[100001][3] = { 0,0,0,1,1,1 };
int main() {
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
	}
	printf("%d\n", (dp[N][0] + dp[N][1] + dp[N][2]) % 9901);
	return 0;
}