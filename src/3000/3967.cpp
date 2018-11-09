#include<iostream>
#include<vector>
#define fi first
#define se second
#define base (1-'A')
using namespace std;
typedef pair<int, int> pi;
char map[6][10];
pi m[6][10], val[7];
int visit[13];
vector<pi> p;
void back(int i, int v, pi& v1, pi& v2) {
	v1.fi -= v; v1.se--;
	v2.fi -= v; v2.se--;
	visit[v] = 0;
	map[p[i].se][p[i].fi] = 'x';
}
int func(int i) {
	if (i == p.size()) return 1;
	for (char ch = 'A'; ch <= 'L'; ch++) {
		int t = ch + base;
		pi& v1 = val[m[p[i].se][p[i].fi].fi];
		pi& v2 = val[m[p[i].se][p[i].fi].se];
		if (visit[t] || v1.fi + t > 26 || v2.fi + t > 26) continue;
		map[p[i].se][p[i].fi] = ch;
		visit[t] = 1;
		v1.fi += t; v1.se++;
		v2.fi += t; v2.se++;
		if ((v1.se == 4 && v1.fi != 26)
			|| (v2.se == 4 && v2.fi != 26)) {
			back(i, t, v1, v2);
			continue;
		}
		if (func(i + 1)) return 1;
		back(i,t, v1, v2);
	}
	return 0;
}
int main() {
	m[0][4] = { 1,2 }; m[1][1] = { 3,4 }; m[1][3] = { 1, 3 }; m[1][5] = { 2,3 }; m[1][7] = { 3,6 };
	m[2][2] = { 1,4 }; m[2][6] = { 2,6 }; m[3][1] = { 1,5 }; m[3][3] = { 4,5 }; m[3][5] = { 5,6 };
	m[3][7] = { 2,5 }; m[4][4] = { 4,6 };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] >= 'A' && map[i][j] <= 'L') {
				int t = map[i][j] + base;
				visit[t] = 1;
				val[m[i][j].fi].fi += t;
				val[m[i][j].fi].se++;
				val[m[i][j].se].fi += t;
				val[m[i][j].se].se++;
			}
			else if (map[i][j] == 'x') p.push_back({ j, i });
		}
	}
	func(0);
	for (int i = 0; i < 5; i++) printf("%s\n", map[i]);
	return 0;
}