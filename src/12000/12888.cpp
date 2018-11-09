#include<cstdio>
unsigned long long dp[61] = { 1 };
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		if (i & 1) dp[i] = (dp[i - 1]-1) * 2 + 1;
		else dp[i] = dp[i - 1] * 2 + 1;
	}
	printf("%llu", dp[n]);
	return 0;
}