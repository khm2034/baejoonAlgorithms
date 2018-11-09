#include<cstdio>
#include<memory.h>
int T, N, dp[3][100001], arr[2][100001];
inline int max(int x, int y) {
	return x > y ? x : y;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < 2; i++) for (int j = 0; j < N; j++) scanf("%d", &arr[i][j]);
		dp[0][0] = arr[0][0]; dp[1][0] = arr[1][0];
		dp[0][1] = arr[0][1] + dp[1][0]; dp[1][1] = arr[1][1] + dp[0][0]; dp[2][1] = max(dp[0][0], dp[1][0]);
		for (int i = 2; i < N; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + arr[1][i];
			dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]);
		}
		printf("%d\n", max(max(dp[0][N-1], dp[1][N-1]), dp[2][N-1]));
	}
	return 0;
}
