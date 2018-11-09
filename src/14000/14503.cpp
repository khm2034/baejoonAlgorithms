#include<iostream>
using namespace std;
int N, M, map[51][51], sx, sy, dir, cnt, tx, ty;
int dx[4] = { 0, -1, 0, 1 }, dy[4] = { -1, 0, 1, 0 };
void func(int x, int y, int d) {
	bool flag = false;
	while (1) {
		if (map[y][x] == 0) {
			cnt++;
			map[y][x] = 2;
		}
		flag = false;
		for (int i = 0, td = d; i < 4; i++) {
			td = (td+1)%4;
			tx = x + dx[td], ty = y + dy[td];
			if (!map[ty][tx]) {
				flag = true;
				d = td;
				x = tx, y = ty;
				break;
			}
		}
		if (!flag) {
			tx = x - dx[d], ty = y - dy[d];
			if(map[ty][tx] == 1) break;
			else x = tx, y = ty;
		}
	}
}
int main() {
	cin >> N >> M >> sy >> sx >> dir;
	if (dir & 1) dir = dir ^ 2;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> map[i][j];
	func(sx, sy, dir);
	cout << cnt << "\n";
	return 0;
}