#include<cstdio>
#define max(a, b) a>b ? a : b
int arr[1001], dp[1001] = { 1,0 }, N, mx= 1;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	for (int i = 1; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j <= i; j++)
			if (dp[j] >= dp[i] && arr[j] < arr[i])
				dp[i] = dp[j] + 1;
		mx = max(mx, dp[i]);
	}
	printf("%d\n", mx);
	return 0;
}