#include<cstdio>
#include<queue>
#define abs(a,b) (a>b?a-b:b-a)
struct p { int x, y; };
int N, L, R, a[51][51], v[51][51], c, dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }, ret;
bool safe(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }
void bfs(int x, int y) {
	std::queue<p> q, tq;
	q.push({ x, y }); tq.push({ x,y });
	v[y][x] = ret;
	int sum = a[y][x];
	while (!q.empty()) {
		p t = q.front(); q.pop();
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = t.x + dx[i], ty = t.y + dy[i];
			if (safe(tx, ty) && v[ty][tx] != ret
				&& (abs(a[t.y][t.x], a[ty][tx]) >= L && abs(a[t.y][t.x], a[ty][tx]) <= R)){
				sum += a[ty][tx];
				v[ty][tx] = ret;
				q.push({ tx, ty });
				tq.push({ tx, ty });
			}
		}
	}
	sum /= tq.size();
	while (!tq.empty()) {
		p t = tq.front(); tq.pop();
		a[t.y][t.x] = sum;
	}
}
int main() {
	scanf("%d%d%d", &N, &L, &R);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &a[i][j]);
	do {
		ret++;
		c = 0;
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
			if (v[i][j] == ret) continue;
			bfs(j, i);
			c++;
		}
	} while (c != N * N);
	printf("%d", ret-1);
	return 0;
}