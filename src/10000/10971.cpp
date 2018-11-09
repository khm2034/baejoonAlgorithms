#include<cstdio>
#define min(a, b) a>b ? b : a
int N, map[11][11], ret = 1e9;
bool visit[11];
void dfs(int cnt, int cost, int loc) {
	if (cnt == N) {
		if (map[loc][0]) ret = min(ret, cost + map[loc][0]);
		return;
	}
	for (int i = 0; i < N; i++)
		if (!visit[i] && map[loc][i]) {
			visit[i] = true;
			dfs(cnt + 1, cost + map[loc][i], i);
			visit[i] = false;
		}
	return;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &map[i][j]);
	visit[0] = true;
	dfs(1, 0, 0);
	printf("%d\n", ret);
	return 0;
}