#include<cstdio>
int N, dp[1001][11], ret;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < 10; i++) dp[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 9, t=0; j >= 0; j--) {
			t = (t+ dp[i - 1][j])%10007;
			dp[i][j] = t;
		}
	}
	for (int i = 0; i < 10; i++) 
		ret = (ret + dp[N][i]) % 10007;
	printf("%d\n", ret);
}