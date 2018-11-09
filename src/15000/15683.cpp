#include<cstdio>
#include<vector>
#include<memory.h>
struct p { int x, y, id; };
int N, M, m[9][9], e, dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }, ret = 1e9;
std::vector<p> vec, five;
bool safe(int x, int y) {
	return x >= 0 && x < M && y >= 0 && y < N;
}
void fill(int x, int y, int d) {
	d = d % 4;
	x += dx[d], y += dy[d];
	while (safe(x, y) && m[y][x] != 6) {
		if (!m[y][x]) {
			e--;
			m[y][x] = -1;
		}
		x += dx[d], y += dy[d];
	}
}
void func(int c) {
	if (c == vec.size()) {
		ret = ret > e ? e : ret;
		return;
	}
	int save[9][9], save_e;
	memcpy(save, m, sizeof(m));
	save_e = e;
	switch (vec[c].id) {
	case 1:
		for (int i = 0; i < 4; i++) {
			fill(vec[c].x, vec[c].y, i);
			func(c + 1);
			memcpy(m, save, sizeof(m));
			e = save_e;
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++) {
			fill(vec[c].x, vec[c].y, i);
			fill(vec[c].x, vec[c].y, i + 2);
			func(c + 1);
			memcpy(m, save, sizeof(m));
			e = save_e;
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++) {
			fill(vec[c].x, vec[c].y, i);
			fill(vec[c].x, vec[c].y, i + 1);
			func(c + 1);
			memcpy(m, save, sizeof(m));
			e = save_e;
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++) {
			fill(vec[c].x, vec[c].y, i);
			fill(vec[c].x, vec[c].y, i + 1);
			fill(vec[c].x, vec[c].y, i + 2);
			func(c + 1);
			memcpy(m, save, sizeof(m));
			e = save_e;
		}
		break;
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++) for (int j = 0; j < M; j++) {
		scanf("%d", &m[i][j]);
		if (!m[i][j]) e++;
		else if (m[i][j] < 5) vec.push_back({ j, i, m[i][j] });
		else if (m[i][j] == 5) five.push_back({ j,i, 5 });
	}
	for (p t : five) for (int i = 0; i < 4; i++) fill(t.x, t.y, i);
	func(0);
	printf("%d", ret);
	return 0;
}