#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<memory.h>
#include<math.h>
using namespace std;
int N, K;
vector<pair<int,pair<int, int>>> trans;
int dp[1005][1005];
int visit[1005];
bool bfs(int mid) {
	queue<pair<int ,int>> q;
	memset(visit, 0, sizeof(visit));
	q.push({ 0,0 });
	visit[0] = -1;
	while (!q.empty()) {
		pair<int,int> t = q.front(); q.pop();
		if (dp[t.first][1] <= mid) return true;
		if (t.second == K+1 || t.first == 1) continue;
		for (int i = 2; i < N + 2; i++) {
			if (visit[i]) continue;
			if (dp[t.first][i] > mid) continue;
			visit[i] = dp[t.first][i];
			q.push({ i, t.second + 1 });
		}
	}
	return false;
}
int main() {
	scanf("%d%d", &N, &K);
	trans.push_back({ 0,{ 0,0 } }); trans.push_back({ 1,{ 10000,10000 } });
	dp[0][0] = dp[1][1] = -1; dp[0][1] = dp[1][0] = ceil(sqrt(10000*10000*2)/10.0);
	for (int i = 1, x, y; i <= N; i++){
		scanf("%d%d", &x, &y);
		for (auto v : trans) {
			int t = ceil(sqrt((v.second.first - x)*(v.second.first - x)
				+ (v.second.second - y)*(v.second.second - y))/10.0);
			dp[i + 1][v.first] = dp[v.first][i + 1] = t;
			dp[i + 1][i + 1] = 1e9;
		}
		trans.push_back({ i+1,{ x, y } });
	}
	int le = 0, ri = 1000, mid;
	while (le <= ri) {
		mid = (le + ri) / 2;
		if (bfs(mid))ri = mid - 1;
		else le = mid + 1;
	}
	printf("%d\n", le);
	return 0;
}