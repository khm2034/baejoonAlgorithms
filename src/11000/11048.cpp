#include<cstdio>
#define max(a, b) (a>b ? a : b)
int N, M, dp[1001][1001];
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1, t; i <= N; i++) 
		for (int j = 1; j <= M; j++) {
			scanf("%d", &t);
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + t;
		}
	printf("%d\n", dp[N][M]);
	return 0;
}