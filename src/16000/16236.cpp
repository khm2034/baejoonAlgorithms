#include<cstdio>
#include<queue>
struct p { int x, y; };
int N, m[21][21], ret, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 }, a = 2, c, r;
p s;
int bfs() {
	std::queue<p> q;
	int v[21][21] = { 0 }, ret = 1e9;
	v[s.y][s.x] = 1;
	q.push(s);
	s = { 22, 22 };
	while (!q.empty()) {
		p t = q.front(); q.pop();
		if (v[t.y][t.x] > ret) break;
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = t.x + dx[i], ty = t.y + dy[i];
			if (tx >= 0 && tx < N && ty >= 0 && ty < N && !v[ty][tx] && m[ty][tx] <= a) {
				int& val = m[ty][tx];
				if (!val || val == a) {
					v[ty][tx] = v[t.y][t.x] + 1;
					q.push({ tx, ty });
				}
				else {
					if (!(ty < s.y || (ty == s.y && tx < s.x))) continue;
					ret = v[ty][tx] = v[t.y][t.x], s = { tx, ty };
				}
			}
		}
	}
	if (s.x == 22) return 0;
	m[s.y][s.x] = 0;
	return ret;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		scanf("%d", &m[i][j]);
		if (m[i][j] == 9) s = { j,i }, m[i][j] = 0;
	}
	while (r = bfs()) {
		ret += r;
		if (++c == a) a++, c = 0;
	}
	printf("%d", ret);
	return 0;
}