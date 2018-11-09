#include<cstdio>
int N, dp[1001];
int main() {
	scanf("%d", &N);
	for (int i = 1, t; i <= N; i++){
		scanf("%d", &t);
		for (int j = 1, k = i - 1; j <= k; j++, k--)
			if (dp[j] + dp[k] > t)
				t = dp[j] + dp[k];
		dp[i] = t;
	}
	printf("%d\n", dp[N]);
	return 0;
}