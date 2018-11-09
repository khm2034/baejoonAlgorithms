#include<iostream>
#include<queue>
#include<algorithm>
#include<memory.h>
using namespace std;

int N, map[101][101], visit[101][101], mi = 1e8;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
bool safe(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}
void bfs_split(int x, int y, int id) {
	queue<pair<int, int>> q;
	map[y][x] = id;
	visit[y][x] = 1;
	q.push({ x, y });
	while (!q.empty()) {
		pair<int, int> t = q.front(); q.pop();
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = t.first + dx[i], ty = t.second + dy[i];
			if (safe(tx, ty) && !visit[ty][tx] && map[ty][tx]) {
				map[ty][tx] = id;
				visit[ty][tx] = 1;
				q.push({ tx, ty });
			}
		}
	}
}
void input_data() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &map[i][j]);
	int id = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] && !visit[i][j])
				bfs_split(j, i, id++);
}
int bfs(int x, int y, int dep, int id) {
	queue<pair<int, int>> q;
	memset(visit, 0, sizeof(visit));
	visit[y][x] = 1;
	q.push({ x, y });
	while (!q.empty()) {
		pair<int, int> t = q.front(); q.pop();
		if (visit[t.second][t.second] >= dep) break;
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = t.first + dx[i], ty = t.second + dy[i];
			if (safe(tx, ty) && !visit[ty][tx])
				if(!map[ty][tx]) {
					visit[ty][tx] = visit[t.second][t.first] + 1;
					q.push({ tx, ty });
				}
				else if (map[ty][tx] != id)
					return visit[t.second][t.first];	
		}
	}
	return 1e8;
}
void solution() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j])
				mi = min(mi, bfs(j, i, mi, map[i][j]));
	printf("%d\n", mi - 1);
}
int main() {
	input_data();
	solution();
	return 0;
}