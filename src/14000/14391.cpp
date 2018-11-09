#include<cstdio>
#define max(a, b) a>b ? a:b
int map[4][4], N, M, mx;
bool visit[4][4];
int calc() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		int row = 0;
		for (int j = 0; j < M; j++) {
			if (visit[i][j]) {
				ret += row;
				row = 0;
			}
			else {
				row = row * 10 + map[i][j];
			}
		}
		ret += row;
	}
	for (int j = 0; j < M; j++) {
		int col = 0;
		for (int i = 0; i < N; i++) {
			if (!visit[i][j]) {
				ret += col;
				col = 0;
			}
			else {
				col = col * 10 + map[i][j];
			}
		}
		ret += col;
	}
	return ret;
}
void func(int x, int y, int cnt) {
	if (!cnt) {
		mx = max(mx, calc());
		return;
	}
	for (int i = y; i < N; i++) {
		for (int j = x; j < M; j++) {
			visit[i][j] = true; func(j + 1, i, cnt - 1);
			visit[i][j] = false; func(j + 1, i, cnt - 1);
		}
		x = 0;
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%1d", &map[i][j]);
	func(0, 0, N*M);
	printf("%d", mx);
	return 0;
}