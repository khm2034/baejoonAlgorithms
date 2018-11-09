#include<cstdio>
#include<queue>
using namespace std;
struct p {
	int x, y;
};
char map[101][101];
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }, N, visit[2][101][101];
bool safe(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}
void bfs(int x, int y, int k) {
	char c = map[y][x];
	queue<p> q;
	visit[k][y][x] = 1;
	q.push({ x,y });
	while (!q.empty()) {
		p t = q.front(); q.pop();
		if (map[t.y][t.x] == 'G') map[t.y][t.x] = 'R';
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = t.x + dx[i], ty = t.y + dy[i];
			if (safe(tx, ty) && !visit[k][ty][tx] && map[ty][tx] == c) {
				visit[k][ty][tx] = 1;
				q.push({ tx, ty });
			}
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%s", map[i]);
	for (int k = 0; k < 2; k++) {
		int cnt = 0;
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
			if (!visit[k][i][j]) {
				bfs(j, i, k);
				cnt++;
			}
		}
		printf("%d ", cnt);
	}
	return 0;
}