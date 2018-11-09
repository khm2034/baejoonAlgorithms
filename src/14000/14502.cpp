#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<memory.h>
using namespace std;
int N, M, map[9][9], zero, mx;
queue<pair<int, int >> tq;
bool tvisit[9][9];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
void input_data(){
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				tq.push({ j,i });
				tvisit[i][j] = true;
			}
			else if (!map[i][j]) zero++;
		}
}
bool safe(int x, int y) {
	return x >= 0 && x < M && y >= 0 && y < N;
}
int bfs(int m[9][9]) {
	queue<pair<int, int >> q;
	q = tq;
	bool visit[9][9];
	int tzero = zero-3;
	memcpy(visit, tvisit, sizeof(visit));
	while (!q.empty()) {
		pair<int, int> t = q.front(); q.pop();
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = t.first + dx[i];
			ty = t.second + dy[i];
			if (safe(tx, ty) && !visit[ty][tx] && !m[ty][tx]) {
				tzero--;
				visit[ty][tx] = true;
				q.push({ tx, ty });
			}
		}
	}
	return tzero;
}
void solution(int x, int y, int cnt) {
	if (cnt == 3) {
		mx = max(bfs(map), mx);
		return;
	}
	for (int i = y; i < N; i++) {
		for (int j = x; j < M; j++) {
			if (map[i][j]) continue;
			map[i][j] = 1;
			solution(j+1, i, cnt + 1);
			map[i][j] = 0;
		}
		x = 0;
	}
	return;
}
int main() 
{
	input_data();
	solution(0, 0, 0);
	printf("%d\n", mx);
	return 0;
}