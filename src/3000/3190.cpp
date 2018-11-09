#include<cstdio>
#include<queue>
struct p { int x, y; };
int N, m[101][101] = { 1 }, K, d = 0, dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }, L, x, y,cnt;
std::queue<p> q;
bool safe(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }
bool move() {
	x += dx[d], y += dy[d], cnt++;
	p t = q.front();
	if (!safe(x, y) || m[y][x] == 1) return false;
	q.push({ x,y });
	if (!m[y][x]) {
		q.pop();
		m[t.y][t.x] = 0;
	}
	m[y][x] = 1;
	return true;
}
int main() {
	scanf("%d%d", &N, &K);
	while(K--) {
		int a, b;
		scanf("%d%d", &a, &b);
		m[a - 1][b - 1] = 2;
	}
	q.push({ 0,0 });
	scanf("%d", &L);
	bool f = true;
	while(L-- && f) {
		int tm; char c;
		scanf("%d %c", &tm, &c);
		while (f && cnt < tm ) f = move();
		if (c == 'L') d--,d = d < 0 ? 3 : d;
		else d++, d = d > 3 ? 0 : d;
	}
	while (f) f = move();
	printf("%d", cnt);
	return 0;
}