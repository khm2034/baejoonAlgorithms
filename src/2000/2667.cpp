#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
struct p { int x, y; };
std::queue<p> q;
std::vector<int> vec;
int N, v[27][27], dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
char m[27][27];
bool safe(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}
void bfs(int x, int y) {
	int c = 1;
	q.push({ x, y });
	v[y][x] = 1;
	while (!q.empty()) {
		p t = q.front(); q.pop();
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = t.x + dx[i], ty = t.y + dy[i];
			if (safe(tx, ty) && !v[ty][tx] && m[ty][tx] == '1') {
				v[ty][tx] = 1;
				q.push({ tx, ty });
				c++;
			}
		}
	}
	vec.push_back(c);
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%s", m[i]);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		if (m[i][j] == '1' && !v[i][j]) bfs(j, i);
	}
	std::sort(vec.begin(), vec.end());
	printf("%d\n", vec.size());
	for (int a : vec) printf("%d\n", a);
	return 0;
}