#include<cstdio>
#define max(a,b) (a>b ? a : b)
typedef long long ll;
ll dp[101] = { 0,1,2,3 }, N, mx;
int main() {
	scanf("%lld", &N);
	if (N <= 3) printf("%lld\n", N);
	else {
		for (ll i = 4; i <= N; i++) {
			dp[i] = dp[i - 1] + 1;
			for (ll j = i - 3, l=3; j >= 1; j--, l++)
				dp[i] = max(dp[i], max(dp[j] * 2, dp[j - 1] * l));
		}
		printf("%lld\n", dp[N]);
	}
	return 0;
}