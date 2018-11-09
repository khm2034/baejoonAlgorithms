#include<cstdio>
#define min(a,b) (a>b ? b : a)
int n, k, arr[101], dp[10001];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 1, mi=1e6; i <= k; i++, mi = 1e6) {
		for (int j = 0; j < n; j++) 
			if (i - arr[j] >= 0) mi = min(mi, dp[i - arr[j]] + 1);
		dp[i] = mi;
	}
	printf("%d\n", dp[k]<1e5 ? dp[k] : -1);
	return 0;
}