#include<cstdio>
int N, arr[2001], M, dp[2001][2001];
int func(int a, int b) {
	if (a >= b) return dp[a][b] = 2;
	if (dp[a][b]) return dp[a][b];
	if (arr[a] != arr[b]) return dp[a][b] = 1;
	else return dp[a][b] = func(a + 1, b - 1);
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	scanf("%d", &M);
	for (int i = 0,a, b; i < M; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", func(a - 1, b - 1)-1);
	}
	return 0;
}