#include<cstdio>
int n, dp[1001] = { 1,1 };
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	printf("%d\n", dp[n]);
	return 0;
}