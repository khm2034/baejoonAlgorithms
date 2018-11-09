#include<cstdio>
#include<memory.h>
char map[502][502], d[4] = { 'U', 'R', 'D', 'L' }, md;
int N, M, sx, sy, dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 }, mx, visit[501][501];
int func(int x, int y, int dir) {
	int cnt = 1;
	visit[y][x] = dir;
	while (1) {
		x += dx[dir], y += dy[dir];
		if (!(x >= 0 && x < M && y >= 0 && y < N) || map[y][x] == 'C') return cnt;
		if (dir == visit[y][x]) return 0;
		if (map[y][x] == '\\') dir = 3 - dir;
		if (map[y][x] == '/') dir = 1 ^ dir;
		cnt++;
		visit[y][x] = dir;
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%s", map[i]);
	scanf("%d%d", &sy, &sx);
	for (int i = 0, t; i < 4; i++) {
		memset(visit, -1, sizeof(visit));
		t = func(sx - 1, sy - 1, i);
		if (!t) {
			printf("%c\nVoyager", d[i]);
			return 0;
		}
		if (t > mx) mx = t, md = d[i];
	}
	printf("%c\n%d", md, mx);
	return 0;
}