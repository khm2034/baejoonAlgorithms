#include<iostream>
#include<queue>
#include<algorithm>
#include<memory.h>
#define fi first
#define se second
using namespace std;
int T, H, W, map[102][102], visit[3][102][102];
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> p;
queue<pair<int, int>> q;
bool safe(int x, int y) {
	return x >= 0 && x <= W + 1 && y >= 0 && y <= H + 1;
}
void bfs(int id, int x, int y) {
	q.push({ x, y });
	visit[id][y][x] = 1;
	while (!q.empty()) {
		pair<int, int> t = q.front(); q.pop();
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = t.fi + dx[i], ty = t.se + dy[i];
			if (safe(tx, ty) && map[ty][tx] != -1) {
				if (map[ty][tx] && (!visit[id][ty][tx] || 
					visit[id][ty][tx] > visit[id][t.se][t.fi] +1)) {
					visit[id][ty][tx] = visit[id][t.se][t.fi] + 1;
					q.push({ tx, ty });
				}
				else if (!map[ty][tx] && (!visit[id][ty][tx] ||
					visit[id][ty][tx] > visit[id][t.se][t.fi])) {
					visit[id][ty][tx] = visit[id][t.se][t.fi];
					q.push({ tx, ty });
				}
			}
		}
	}
}
void input_data() {
	memset(visit, 0, sizeof(visit));
	memset(map, 0, sizeof(map));
	p.clear(); p.push_back({ 0,0 });
	char t;
	for (int i = 1, id = 1; i <= H; i++)
		for (int j = 1; j <= W; j++) {
			scanf(" %c", &t);
			if (t == '*') map[i][j] = -1;
			else if (t == '#') map[i][j] = 1;
			else if (t == '$') {
				p.push_back({ j, i });
			}
		}
}
void solution() {
	int ret = 1e9;
	for (int i = 0; i < 3; i++)
		bfs(i, p[i].first, p[i].second);
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			if (visit[0][i][j] && visit[1][i][j] && visit[2][i][j])
				ret = min(ret, visit[0][i][j] + visit[1][i][j] + visit[2][i][j] - (map[i][j] == 1 ? 2 : 0));
	printf("%d\n", ret - 3);
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &H, &W);
		input_data();
		solution();
	}
	return 0;
}