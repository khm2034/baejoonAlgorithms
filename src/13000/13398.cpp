#include<cstdio>
#include<algorithm>
using namespace std;
int dp[2][100001], N, arr[100001], mx;
inline int max(int x, int y) {
	return x > y ? x : y;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	dp[0][0] = arr[0]; mx = dp[0][0];
	for (int i = 1; i < N; i++) {
		dp[0][i] = arr[i];
		dp[0][i] = max(0, max(dp[0][i], dp[0][i-1] + arr[i]));
		dp[1][i] = max(0, max(dp[0][i-1], dp[1][i-1] + arr[i]));
		mx = max(mx, max(dp[0][i], dp[1][i]));
	}
	if (!mx) {
		sort(arr, arr + N);
		mx = arr[N - 1];
	}
	printf("%d\n", mx);
	return 0;
}