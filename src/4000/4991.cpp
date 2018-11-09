#include<cstdio>
#include<queue>
#include<memory.h>
#define fi first
#define se second
#define min(a,b) a>b?b:a
using namespace std;
typedef pair<int, int> pii;
char map[21][21];
int W, H, sx, sy, idx, dp[11][11], dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0 ,-1 }, mi;
pii loc[11];
int bfs(int c, int n) {
	if (dp[c][n]) return dp[c][n];
	queue<pii> q;
	int visit[20][20] = { 0 };
	pii t = loc[c];
	q.push({ t.fi, t.se });
	visit[t.se][t.fi] = 1;
	while (!q.empty()) {
		t = q.front(); q.pop();
		if (loc[n].fi == t.fi && loc[n].se == t.se) return dp[c][n] = visit[t.se][t.fi] - 1;
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = t.fi + dx[i], ty = t.se + dy[i];
			if (tx >= 0 && tx < W && ty >= 0 && ty < H && map[ty][tx] != 'x' && !visit[ty][tx]) {
				visit[ty][tx] = visit[t.se][t.fi] + 1;
				q.push({ tx, ty });
			}
		}
	}
	return -1;
}
int func(int cur, int visit, int cnt) {
	if (cnt >= mi) return 0;
	if (visit == (1 << idx) - 2) {
		mi = min(mi, cnt);
		return 0;
	}
	for (int i = 1; i < idx; i++) {
		if (visit & (1 << i)) continue;
		int t = bfs(cur, i);
		if (t < 0) return -1;
		if (func(i, visit | (1 << i), cnt + t)) return -1;
	}
}
int main() {
	while (1) {
		scanf("%d%d", &W, &H);
		if (!W && !H) break;
		memset(dp, 0, sizeof(dp));
		memset(loc, 0, sizeof(loc));
		idx = 1, mi = 1e9;
		for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'o') loc[0] = { j,i };
			if (map[i][j] == '*') loc[idx++] = { j,i };
		}
		if (func(0, 0, 0)) printf("-1\n");
		else printf("%d\n", mi);
	}
	return 0;
}