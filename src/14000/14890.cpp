#include<cstdio>
int m[101][101], N, L, dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 },cnt;
bool safe(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}
int func(int x, int y, int d) {
	int v[101][101] = { 0 }, pre = m[y][x];
	while (1) {
		x += dx[d], y += dy[d];
		if (!safe(x, y)) break;
		if (pre == m[y][x]) continue;
		if (m[y][x] > pre + 1 || pre > m[y][x] + 1) return 0;
		int nx = x, ny = y;
		if (pre > m[y][x]) {
			nx -= dx[d], ny -= dy[d];
			for (int i = 0; i < L; i++) {
				nx += dx[d], ny += dy[d];
				if (!safe(nx,ny)|| v[ny][nx] || m[y][x] != m[ny][nx]) return 0;
				v[ny][nx] = 1;
			}
			x = nx, y = ny;
		}
		else {
			for (int i = 0; i < L; i++) {
				nx -= dx[d], ny -= dy[d];
				if (!safe(nx, ny) || v[ny][nx] || m[y-dy[d]][x-dx[d]] != m[ny][nx]) return 0;
				v[ny][nx] = 1;
			}
		}
		pre = m[y][x];
	}
	return 1;
}
int main() {
	scanf("%d%d", &N, &L);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &m[i][j]);
	for (int i = 0; i < N; i++) cnt += (func(i, 0, 0) + func(0, i, 1));
	printf("%d", cnt);
	return 0;
}