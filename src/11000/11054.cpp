#include<cstdio>
int N, arr[1001], dp[2][1001], ret = 1;
inline int max(int x, int y) {
	return x > y ? x : y;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	dp[0][0] = dp[1][0] = 1;
	for (int i = 1; i < N; i++) {
		dp[0][i] = 1;
		for (int j = 0; j < i; j++) {
			if (dp[0][i] <= dp[0][j] && arr[i] > arr[j])
				dp[0][i] = dp[0][j] + 1;
			if (dp[1][i] <= dp[1][j] && arr[i] < arr[j])
				dp[1][i] = dp[1][j] + 1;
			if (dp[1][i] <= dp[0][j] && arr[i] < arr[j])
				dp[1][i] = dp[0][j] + 1;
		}
		ret = max(ret, max(dp[0][i], dp[1][i]));
	}
	printf("%d\n",ret);
	return 0;
}