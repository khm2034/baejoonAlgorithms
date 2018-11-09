#include<cstdio>
#define max(a, b) a>b?a:b
int N, M, map[501][501], ret, dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
bool visit[501][501];
void input_data() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &map[i][j]);
}
bool safe(int x, int y) {
	return x >= 0 && x < M && y >= 0 && y < N;
}
void func(int x, int y, int sum, int cnt) {
	visit[y][x] = 1;
	if (cnt == 4) {
		ret = max(ret, sum);
		visit[y][x] = 0;
		return;
	}
	for (int i = 0, tx, ty; i < 4; i++) {
		tx = x + dx[i], ty = y + dy[i];
		if (safe(tx, ty)) {
			if (visit[ty][tx]) {
				do {
					tx += dx[i], ty += dy[i];
				} while (safe(tx, ty) && visit[ty][tx]);
			}
			func(tx, ty, sum + map[ty][tx], cnt + 1);
		}
	}
	visit[y][x] = 0;
}
void solution() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			func(j, i, map[i][j], 1);
	printf("%d\n", ret);
}
int main() {
	input_data();
	solution();
	return 0;
}