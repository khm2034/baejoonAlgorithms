#include<iostream>
#include<queue>
#include<vector>
#include<memory.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pi;
int T, H, W, map[103][103], dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
vector<pi> door[26];
queue<pi> q;
bool safe(int x, int y) {
	return x >= 0 && x <= W + 1 && y >= 0 && y <= H + 1;
}
void bfs() {
	q.push({ 0, 0 });
	bool visit[103][103] = { 1, 0 };
	int cnt = 0;
	while (!q.empty()) {
		pi t = q.front(); q.pop();
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = t.fi + dx[i], ty = t.se + dy[i];
			if (safe(tx, ty) && (map[ty][tx] != -1 || !(map[ty][tx] >= 'A' && map[ty][tx] <= 'Z'))) {
				if (map[ty][tx] == 1 && !visit[ty][tx]) {
					cnt++;
					map[ty][tx] = 0;
					visit[ty][tx] = true;
					q.push({ tx, ty });
				}
				else if ((map[ty][tx] >= 'a' && map[ty][tx] <= 'z') && !visit[ty][tx]) {
					for (auto v : door[map[ty][tx] - 'a'])
						map[v.se][v.fi] = 0;
					map[ty][tx] = 0;
					queue<pi> t;
					q.swap(t);
					memset(visit, 0, sizeof(visit));
					q.push({ tx, ty });
					visit[ty][tx] = true;
				}
				else if (!map[ty][tx] && !visit[ty][tx]) {
					visit[ty][tx] = true;
					q.push({ tx, ty });
				}
			}
		}
	}
	printf("%d\n", cnt);
}
void init() {
	for (int i = 0; i < 26; i++)
		door[i].clear();
	memset(map, 0, sizeof(map));
}
void input_data() {
	init();
	char c, key[27];
	scanf("%d%d", &H, &W);
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++) {
			scanf(" %c", &c);
			if (c == '*') map[i][j] = -1;
			else if (c == '$') map[i][j] = 1;
			else if (c >= 'A' && c <= 'Z') {
				door[c - 'A'].push_back({ j,i });
				map[i][j] = (int)c;
			}
			else if (c >= 'a' && c <= 'z') map[i][j] = (int)c;
		}
	scanf("%s", key);
	if (key[0] != '0') {
		for (int i = 0; key[i]; i++) {
			for (auto v : door[key[i] - 'a'])
				map[v.se][v.fi] = 0;
		}
	}
}
int main() {
	scanf("%d", &T);
	while (T--) {
		input_data();
		bfs();
	}
	return 0;
}