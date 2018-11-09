#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N, map[101][101], mx, mi=101, ret=1, visit[101][101];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;
bool safe(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}
void bfs(int x, int y, int dep) {
	visit[y][x] = dep;
	q.push({ x,y });
	while (!q.empty()) {
		pair<int, int> t = q.front(); q.pop();
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = t.first + dx[i], ty = t.second + dy[i];
			if (safe(tx, ty) && visit[ty][tx] != dep && map[ty][tx] > dep) {
				visit[ty][tx] = dep;
				q.push({ tx, ty });
			}
		}
	}
}
int func(int dep) {
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] > dep && visit[i][j] != dep) {
				bfs(j, i, dep);
				cnt++;
			}
	return cnt;
}
void solution() {
	for (int i = mi; i <= mx; i++) {
		ret = max(ret, func(i));
	}
	printf("%d\n", ret);
}
void input_data() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			mx = max(mx, map[i][j]);
			mi = min(mi, map[i][j]);
		}
}
int main() {
	input_data();
	solution();
	return 0;
}