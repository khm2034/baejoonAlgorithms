#include<cstdio>
#include<queue>
struct p { int x, y, z; };
std::queue<p> q;
int M, N, H, m[101][101][101], z, dx[6] = { 1,0,-1,0,0,0 }, dy[6] = { 0,1,0,-1,0,0 }, dz[6] = { 0,0,0,0,1,-1 }, mx=1;
bool safe(int x, int y, int z) {
	return x >= 0 && x < M && y >= 0 && y < N && z >= 0 && z < H;
}
void bfs() {
	while (!q.empty()) {
		p t = q.front(); q.pop();
		for (int i = 0, tx, ty, tz; i < 6; i++) {
			tx = t.x + dx[i], ty = t.y + dy[i], tz = t.z + dz[i];
			if (safe(tx, ty, tz) && !m[tz][ty][tx]) {
				m[tz][ty][tx] = m[t.z][t.y][t.x] + 1;
				mx = mx < m[tz][ty][tx] ? m[tz][ty][tx] : mx;
				z--;
				q.push({ tx, ty, tz });
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &M, &N, &H);
	for (int i = 0; i < H; i++) for (int j = 0; j < N; j++) for (int k = 0; k < M; k++) {
		int& t = m[i][j][k];
		scanf("%d", &t);
		if (!t) z++;
		if (t == 1) q.push({ k,j,i });
	}
	bfs();
	printf("%d", z > 0 ? -1 : mx - 1);
	return 0;
}