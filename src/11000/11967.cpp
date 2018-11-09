#include<iostream>
#include<queue>
#include<vector>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pi;
int map[101][101], N, M, visit[101][101], chk[101][101], cnt = 1, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
vector<pi> sw[101][101];
queue<pi> q;
bool safe(int x, int y) {
	return x >= 1 && x <= 100 && y >= 1 && y <= 100;
}
void bfs() {
	visit[1][1] = map[1][1] = 1;
	q.push({ 1,1 });
	while (!q.empty()) {
		pi t = q.front(); q.pop();
		for (auto v : sw[t.se][t.fi]) {
			if (!map[v.se][v.fi]) {
				map[v.se][v.fi] = 1;
				cnt++;
				if (chk[v.se][v.fi]) q.push({ v.fi, v.se });
			}
		}
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = t.fi + dx[i], ty = t.se + dy[i];
			if (safe(tx, ty)){
				if (map[ty][tx] && !visit[ty][tx]) {
					visit[ty][tx] = 1;
					q.push({ tx, ty });
				}
				if (!map[ty][tx]) chk[ty][tx] = 1;
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0, x1, x2, y1, y2; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		sw[y1][x1].push_back({ x2, y2 });
	}
	bfs();
	cout << cnt << "\n";
	return 0;
}