#include<cstdio>
#include<queue>
struct p { int x, y, d; };
int N, M, a[101][101], v[4][101][101], dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 }, mi=1e9, calc[4][4] = { 0, 2, 1, 1, 2, 0, 1, 1, 1, 1, 0, 2, 1, 1, 2, 0 };
std::queue<p> q;
p s, e;
void bfs(){
	q.push(s);
	for (int i = 0; i < 4; i++) v[i][s.y][s.x] = 1 + calc[i][s.d];
	while (!q.empty()) {
		p t = q.front(); q.pop();
		for (int i = 0; i < 4; i++) for (int j = 0, tx = t.x + dx[i], ty = t.y + dy[i]; j < 3; j++, tx += dx[i], ty += dy[i]) {
			if (tx >= 0 && tx < M && ty >= 0 && ty < N){
				if (a[ty][tx]) break;
				if (!v[i][ty][tx] || v[i][ty][tx] > v[t.d][t.y][t.x] + calc[i][t.d] + 1) {
					v[i][ty][tx] = v[t.d][t.y][t.x] + 1 + calc[i][t.d];
					q.push({ tx, ty, i });
				}
			}
		}
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &a[i][j]);
	scanf("%d%d%d%d%d%d", &s.y, &s.x, &s.d, &e.y, &e.x, &e.d);
	s.x--, s.y--, e.x--, e.y--, s.d--, e.d--;
	bfs();
	for (int i = 0, t; i < 4; i++) {
		if (!v[i][e.y][e.x]) continue;
		t = v[i][e.y][e.x] + calc[i][e.d];
		mi = mi > t ? t : mi;
	}
	printf("%d", mi-1);
	return 0;
}