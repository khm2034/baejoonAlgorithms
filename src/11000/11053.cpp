#include<cstdio>
#define max(a,b) a > b ? a : b
int N, dp[1001], arr[1001], mx;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--)
			if (dp[i] <= dp[j] && arr[i] > arr[j])
				dp[i] = dp[j] + 1;
		mx = max(mx, dp[i]);
	}
	printf("%d\n", mx);
	return 0;
}