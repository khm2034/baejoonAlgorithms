#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
char m[101][101];
int N, M, v[101][101], dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
queue<pii> q;
int bfs() {
	v[0][0] = 1;
	q.push({ 0,0 });
	while (!q.empty()) {
		pii t = q.front(); q.pop();
		if (t.first == M - 1 && t.second == N - 1) return v[N-1][M-1];
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = t.first + dx[i], ty = t.second + dy[i];
			if (tx >= 0 && tx < M && ty >= 0 && ty < N 
				&& m[ty][tx] == '1' && !v[ty][tx]) {
				v[ty][tx] = v[t.second][t.first] + 1;
				q.push({ tx, ty });
			}
		}
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf(" %s", m[i]);
	printf("%d",bfs());
	return 0;
}