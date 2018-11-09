#include<cstdio>
#define min(a, b) a>b ? b : a
int N, map[11][11], visit[11][11], ret = 1e6;
void func(int x, int y, int cnt, int val) {
	if (cnt == 3) {
		ret = min(ret, val);
		return;
	}
	for (int i = y; i < N - 1; i++) {
		for (int j = x; j < N - 1; j++) {
			if (visit[i][j] || visit[i + 1][j] || visit[i - 1][j] || visit[i][j + 1] || visit[i][j - 1]) continue;
			visit[i][j] = visit[i + 1][j] = visit[i - 1][j] = visit[i][j + 1] = visit[i][j - 1] = 1;
			func(j + 2, i, cnt + 1, val+ map[i][j] + map[i + 1][j] + map[i - 1][j] + map[i][j + 1] + map[i][j - 1]);
			visit[i][j] = visit[i + 1][j] = visit[i - 1][j] = visit[i][j + 1] = visit[i][j - 1] = 0;
		}
		x = 1;
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &map[i][j]);
	func(1, 1, 0, 0);
	printf("%d\n", ret);
	return 0;
}