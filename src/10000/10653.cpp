#include<cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;
struct p { int x, y; };
int N, K, dp[501][501];
p a[501];
int dis(int i, int j){return  abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);}
int func(int idx, int c) {
	if (idx + c + 1 == N - 1)  return dis(idx, N - 1);
	if (idx + c + 1 > N - 1) return 1e9;
	int& ret = dp[idx][c];
	if (dp[idx][c] != -1) return ret;
	ret = 1e9;
	for (int i = 0; i <= c; i++) ret = min(ret, func(idx + i + 1, c-i) + dis(idx, idx+i+1));
	return ret;
}
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d%d", &a[i].x, &a[i].y);
	memset(dp, -1, sizeof(dp));
	printf("%d", func(0,K));
	return 0;
}