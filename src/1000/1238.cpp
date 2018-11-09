#include<cstdio>
#define min(a,b) (a>b?b:a)
int g[1001][1001], N, M, X, mx;
int main() {
	scanf("%d%d%d", &N, &M, &X);
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++) g[i][j] = i==j ? 0 : 1e9;
	while (M--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = min(g[a][b], c);
		g[a][b] = g[a][b] > c ? c : g[a][b];
	}
	for (int k = 1; k <= N; k++)for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++)
		g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	for (int i = 1; i <= N; i++) mx = mx < g[i][X] + g[X][i] ? g[i][X] + g[X][i] : mx;
	printf("%d", mx);
	return 0;
}