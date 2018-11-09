#include<cstdio>
#include<queue>
struct p { int x, y; };
int N, M, m[101][101], cnt, ret, dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
bool safe(int x, int y) { return x >= 0 && x < M && y >= 0 && y < N; }
int bfs() {
	int c = 0;
	std::queue<p> q, tq;
	int v[101][101] = { 1 };
	q.push({ 0,0 });
	while (!q.empty()) {
		p t = q.front(); q.pop();
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = t.x + dx[i], ty = t.y + dy[i];
			if (safe(tx, ty)) {
				if (m[ty][tx]) v[ty][tx]++;
				else if (!v[ty][tx]) {
					v[ty][tx] = 1;
					q.push({ tx, ty });
				}
			}
		}
	}
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (v[i][j] > 1) {
		m[i][j] = 0;
		c++;
	}
	return c;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		scanf("%d", &m[i][j]);
		if (m[i][j]) cnt++;
	}
	while (cnt) {
		ret++;
		cnt -= bfs();
	}
	printf("%d", ret);
	return 0;
}