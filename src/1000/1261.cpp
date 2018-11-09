#include<iostream>
#include<queue>
using namespace std;

int N, M, map[101][101], visit[101][101];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;
void input_data() {
	char t;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			scanf(" %c", &t);
			map[i][j] = t - '0';
		}
}
bool safe(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < M;
}
void solution() {
	q.push({ 0,0 });
	visit[0][0] = 1;
	while (!q.empty()){
		pair<int, int> t = q.front(); q.pop();
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = t.first + dx[i], ty = t.second + dy[i];
			if (safe(tx, ty)){
				if (map[ty][tx] && (!visit[ty][tx] || visit[ty][tx] > visit[t.second][t.first] + 1)) {
					visit[ty][tx] = visit[t.second][t.first] + 1;
					q.push({ tx, ty });
				}
				else if (!map[ty][tx] && (!visit[ty][tx] || visit[ty][tx] > visit[t.second][t.first])) {
					visit[ty][tx] = visit[t.second][t.first];
					q.push({ tx, ty });
				}
			}
		}
	}
	printf("%d\n", visit[M - 1][N - 1] - 1);
}
int main() {
	input_data();
	solution();
	return 0;
}