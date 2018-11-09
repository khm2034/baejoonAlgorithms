#include<iostream>
#include<algorithm>
using namespace std;
int N, K, dp[101][100001], mx;
pair<int, int> arr[101];
int func(int n, int w) {
	if (w > K) return -arr[n-1].second;
	if (n >= N) return 0;
	int& ret = dp[n][w];
	if (ret != 0) return ret;
	return ret = max(func(n + 1, w), func(n + 1, w+arr[n].first) + arr[n].second);
}
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d%d", &arr[i].first, &arr[i].second);
	printf("%d", func(0, 0));
	return 0;
}