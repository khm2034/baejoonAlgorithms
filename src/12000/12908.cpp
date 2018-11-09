#include<cstdio>
#include<algorithm>
using namespace std;
struct p { int x1, y1, x2, y2; };
int sx, sy, ex, ey, v[3];
long long mi = 2e9 + 5;
p potal[3];
void func(int x, int y, long long d) {
	if (d > mi) return;
	mi = min(mi, d + abs(x - ex) + abs(y - ey));
	for (int i = 0; i < 3; i++) {
		if (v[i]) continue;
		v[i] = 1;
		p t = potal[i];
		func(t.x2, t.y2, d + 10 + abs(x - t.x1) + abs(y - t.y1));
		func(t.x1, t.y1, d + 10 + abs(x - t.x2) + abs(y - t.y2));
		v[i] = 0;
	}
}
int main() {
	scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
	for (int i = 0, a, b, c, d; i < 3; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		potal[i] = { a,b,c,d };
	}
	func(sx, sy, 0);
	printf("%lld", mi);
	return 0;
}