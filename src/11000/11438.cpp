#include<cstdio>
#include<vector>
#include<queue>
std::vector<int> g[100001];
std::queue<int> q;
int p[100001][21], d[100001], N, M, a, b;
void bfs() {
	d[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int n : g[t]) {
			if (d[n]) continue;
			d[n] = d[t] + 1, p[n][0] = t;
			q.push(n);
		}
	}
}
int lca(int a, int b) {
	if (d[a] < d[b]) {
		int c(a); a = b; b = c;
	}
	for (int i = 20; i >= 0; i--) {
		if (d[a] - d[b] >= (1 << i)) a = p[a][i];
	}
	if (a == b) return a;
	for (int i = 20; i >= 0; i--) {
		if (p[a][i] != p[b][i]) a = p[a][i], b = p[b][i];
	}
	return p[a][0];
}
int main() {
	scanf("%d", &N);
	for(int i=0; i<N-1; i++) {
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	scanf("%d", &M);
	bfs();
	for (int i = 1; i < 21; i++)
		for (int j = 1; j <= N; j++)
			p[j][i] = p[p[j][i - 1]][i - 1];
	while (M--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", lca(a, b));
	}
	return 0;
}
