#include<cstdio>
#include<queue>
struct p { int x, y; };
int M, N, a[1001][1001], v[1001][1001], z, dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }, mx=1;
std::queue<p> q;
bool safe(int x, int y) {
	return x >= 0 && x < M && y >= 0 && y < N;
}
void bfs() {
	while (!q.empty()) {
		p t = q.front(); q.pop();
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = t.x + dx[i], ty = t.y + dy[i];
			if (safe(tx, ty) && !v[ty][tx] && !a[ty][tx]) {
				z--;
				v[ty][tx] = v[t.y][t.x]+1;
				mx = mx < v[ty][tx] ? v[ty][tx] : mx;
				q.push({ tx, ty });
			}
		}
	}
}
int main() {
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		scanf("%d", &a[i][j]);
		if (!a[i][j]) z++;
		if (a[i][j] == 1) {
			v[i][j] = 1;
			q.push({ j, i });
		}
	}
	bfs();
	if (z) printf("-1");
	else printf("%d", mx - 1);
	return 0;
}