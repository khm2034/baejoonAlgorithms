#include<iostream>
#include<memory.h>
#include<algorithm>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pi;
int N, M, map[11][11], dx[4] = { 1,0,-1,0 }, dy[4] = { 0, 1, 0, -1 }, ret=1e2;
pi ball[2];
int move(pi b[2], pi pri, int dir) {
	pi& t1 = b[pri.fi];
	pi& t2 = b[pri.se];
	bool m_f = false;
	while (!map[t1.se+dy[dir]][t1.fi+dx[dir]] 
		&& !(t1.se + dy[dir] == t2.se && t1.fi + dx[dir] == t2.fi)) {
		t1.fi += dx[dir], t1.se += dy[dir];
		m_f = true;
	}
	if (map[t1.se + dy[dir]][t1.fi + dx[dir]] == 1 && !pri.fi) t1.fi = t1.se = 0;
	else if (map[t1.se + dy[dir]][t1.fi + dx[dir]] == 1 && pri.fi) return -1;
	while (!map[t2.se + dy[dir]][t2.fi + dx[dir]]
		&& !(t2.se + dy[dir] == t1.se && t2.fi + dx[dir] == t1.fi)) {
		t2.fi += dx[dir], t2.se += dy[dir];
		m_f = true;
	}
	if (map[t2.se + dy[dir]][t2.fi + dx[dir]] == 1 && !pri.se) return 0;
	else if (map[t2.se + dy[dir]][t2.fi + dx[dir]] == 1 && pri.se) return -1;
	if (!t1.fi && !t1.se) return 0;
	if (!m_f) return -1;
	return 1;
}
void func(pi b[2] , int d, int l_d) {
	if (ret <= d) return;
	if (d > 10) return;
	pi pri[4], t_b[2];
	if (b[0].fi < b[1].fi) pri[0] = { 1,0 }, pri[2] = { 0,1 };
	else pri[0] = { 0,1 }, pri[2] = { 1,0 };
	if (b[0].se < b[1].se) pri[1] = { 1,0 }, pri[3] = { 0,1 };
	else pri[1] = { 0,1 }, pri[3] = { 1,0 };
	int save[11][11];
	t_b[0] = b[0], t_b[1] = b[1];
	memcpy(save, map, sizeof(map));
	for (int i = 0; i < 4; i++) {
		if (i == l_d) continue;
		int t = move(b, pri[i], i);
		if (!t) {
			ret = min(ret, d);
			return;
		}
		else if (t == 1) func(b, d + 1, i);
		memcpy(map, save, sizeof(map));
		b[0] = t_b[0], b[1] = t_b[1];
	}
}
int main() {
	scanf("%d%d", &N, &M);
	char c;
	for(int i=0; i<N; i++)
		for (int j = 0; j < M; j++) {
			scanf(" %c", &c);
			if (c == '#') map[i][j] = -1;
			else if (c == 'R') ball[0] = { j, i };
			else if (c == 'B') ball[1] = { j, i };
			else if (c == 'O') map[i][j] = 1;
		}
	func(ball, 1, -1);
	if (ret == 1e2) printf("-1\n");
	else printf("%d\n", ret);
	return 0;
}