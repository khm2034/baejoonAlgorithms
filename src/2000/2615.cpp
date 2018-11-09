#include<cstdio>
int map[19][19], dx[4] = { 1, 1, 1, 0 }, dy[4] = { -1, 0, 1, 1 }, a, b, c;
void input_data() {
	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			scanf("%d", &map[i][j]);
}
bool safe(int x, int y) {
	return x >= 0 && x < 19 && y >= 0 && y < 19;
}
bool chk(int x, int y, int t) {
	int tx = x, ty = y;
	for (int i = 0; i < 4; i++) {
		tx += dx[t], ty += dy[t];
		if (!safe(tx, ty) || map[y][x] != map[ty][tx]) return false;
	}
	if (map[y][x] == map[ty + dy[t]][tx + dx[t]]) return false;
	return true;
}
bool solution() {
	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			if (map[i][j]) {
				for (int k = 0, tx, ty; k < 4; k++) {
					if (safe(j - dx[k], i - dy[k]) && map[i][j] == map[i - dy[k]][j - dx[k]]) continue;
					if (chk(j, i, k)) {
						a = i + 1, b = j + 1, c = map[i][j];
						return true;
					}
				}
			}
	return false;
}
int main() {
	input_data();
	if (solution()) printf("%d\n%d %d\n", c, a, b);
	else printf("0\n");
	return 0;
}