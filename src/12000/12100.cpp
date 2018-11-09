#include<cstdio>
#include<memory.h>
#include<cmath>
#define max(a,b) a>b?a:b
int N, map[21][21], ret, dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int alp[4][2];
bool safe(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}
void move(int d) {
	bool m[21][21] = { 0, };
	for (int i = 0, tx, ty; i<N; i++)
		for (int j = 0; j < N; j++) {
			tx = abs(alp[d][1] - j), ty = abs(alp[d][0] - i);
			if (map[ty][tx]) {
				int v = map[ty][tx];
				map[ty][tx] = 0;
				while (safe(tx + dx[d], ty + dy[d]) && !map[ty + dy[d]][tx + dx[d]]) {
					tx += dx[d], ty += dy[d];
				}
				tx += dx[d], ty += dy[d];
				if (!safe(tx, ty) || map[ty][tx] != v || m[ty][tx]) {
					map[ty - dy[d]][tx - dx[d]] = v;
					continue;
				}
				map[ty][tx] = v * 2;
				m[ty][tx] = true;
			}
		}
}
void func(int dep) {
	if (dep == 5) {
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) ret = max(ret, map[i][j]);
		return;
	}
	int save[21][21];
	memcpy(save, map, sizeof(map));
	for (int i = 0; i < 4; i++) {
		move(i);
		func(dep + 1);
		memcpy(map, save, sizeof(map));
	}
}
int main() {
	scanf("%d", &N);
	alp[0][0] = 0, alp[0][1] = N - 1;
	alp[1][0] = N - 1, alp[1][1] = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &map[i][j]);
	func(0);
	printf("%d\n", ret);
	return 0;
}