#include<cstdio>
#include<queue>
using namespace std;
struct p { int x, y; };
char m[2][51];
int N, b, dx[3] = { 1,0,0 }, dy[4] = { 0,1,-1 }, mx;
void bfs(int x, int y) {
	int v[2][51] = { 0 };
	queue<p> q;
	q.push({ x, y });
	v[y][x] = 1;
	while (!q.empty()) {
		p t = q.front(); q.pop();
		if (t.x == N - 1) {
			int tmp = N * 2 - v[t.y][t.x] - b;
			mx = mx < tmp ? tmp : mx;
			return;
		}
		for (int i = 0, tx, ty; i < 3; i++) {
			tx = t.x + dx[i], ty = t.y + dy[i];
			if (tx >= 0 && tx < N && ty >= 0 && ty < 2 && m[ty][tx] == '.' && !v[ty][tx]) {
				v[ty][tx] = v[t.y][t.x] + 1;
				q.push({ tx, ty });
			}
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i<2; i++) for (int j = 0; j < N; j++) {
		scanf(" %c", &m[i][j]);
		if (m[i][j] == '#') b++;
	}
	for (int i = 0; i < 2; i++) if (m[i][0] == '.') bfs(0, i);
	printf("%d", mx);
	return 0;
}