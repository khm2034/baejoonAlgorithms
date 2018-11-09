#include<cstdio>
#include<queue>
std::queue<int> q;
int g[1001][1001];
int N, M, to, from, v[1001];
void bfs() {
	q.push(from);
	v[from] = 0;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int n = 1; n <= N; n++) {
			if (g[t][n] != 2e9 && v[n] > v[t] + g[t][n]) {
				v[n] = v[t] + g[t][n];
				q.push(n);
			}
		}
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		v[i] = 2e9;
		for (int j = 1; j <= N; j++) g[i][j] = 2e9;
	}
	for (int i = 0, a, b, c; i < M; i++) {
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = g[a][b] > c ? c : g[a][b];
	}
	scanf("%d%d", &from, &to);
	bfs();
	printf("%d", v[to]);
	return 0;
}