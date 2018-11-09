#include<cstdio>
char m[11][11];
int N, M, v[11][11], dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }, sx = 1e3, ex, sy = 1e3, ey;
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf(" %s", m[i]);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		if (m[i][j] == '.')  continue;
		int c = 0;
		for (int k = 0, tx, ty; k < 4; k++) {
			tx = j + dx[k], ty = i + dy[k];
			if ((!(tx >= 0 && tx < M && ty >= 0 && ty < N) || m[ty][tx] == '.') && !v[ty][tx]) c++;
		}
		if (c >= 3) v[i][j] = 1, m[i][j] = '.';
		else {
			sx = sx > j ? j : sx;
			sy = sy > i ? i : sy;
			ex = ex < j ? j : ex;
			ey = ey < i ? i : ey;
		}
	}
	for (int i = sy; i <= ey; i++) {
		for (int j = sx; j <= ex; j++)
			if (m[i][j]) printf("%c", m[i][j]);
		printf("\n");
	}
	return 0;
}