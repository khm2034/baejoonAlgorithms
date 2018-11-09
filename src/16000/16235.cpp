#include<cstdio>
#include<queue>
struct D {int a, cur;};
bool operator<(D a, D b) {
	if (a.cur != b.cur) return a.cur < b.cur;
	return a.a > b.a;
}
int N, M, K, m[11][11], a[11][11], dx[8] = { 1,1,0,-1,-1,-1,0,1 }, dy[8] = {0,1,1,1,0,-1,-1,-1}, ret;
std::priority_queue<D> pq[11][11];
void func(int x, int y) {
	bool f = false;
	while (!pq[y][x].empty()) {
		D t = pq[y][x].top();
		if (t.cur < K) break;
		pq[y][x].pop();
		if (f || m[y][x] < t.a) m[y][x] += (t.a / 2), f = true;
		else {
			m[y][x] -= t.a;
			pq[y][x].push({t.a + 1, K - 1 });
			if ((t.a + 1) % 5 == 0) {
				for (int i = 0, tx, ty; i < 8; i++) {
					tx = x + dx[i], ty = y + dy[i];
					if (tx >= 0 && tx < N && ty >= 0 && ty < N) pq[ty][tx].push({ 1, K - 1 });
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		scanf("%d", &a[i][j]);
		m[i][j] = 5;
	}
	for (int i = 0, x, y, a; i < M; i++) {
		scanf("%d%d%d", &y, &x, &a);
		pq[y-1][x-1].push({a,K });
	}
	while (K--) {
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
			func(j, i);
			m[i][j] += a[i][j];
		}
	}
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) ret += pq[i][j].size();
	printf("%d", ret);
	return 0;
}