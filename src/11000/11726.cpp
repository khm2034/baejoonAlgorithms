#include<cstdio>
int dp[1001] = { 1,1 }, N;
int main() {
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	printf("%d\n", dp[N]);
}