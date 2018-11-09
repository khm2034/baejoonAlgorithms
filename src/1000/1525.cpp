#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
int ret = 1e9, dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
map<int, int> visit;
queue<pair<pair<int,int>,int>> q;
bool safe(int x, int y) {
	return x >= 0 && x < 3 && y >= 0 && y < 3;
}
int make_int(int a[3][3]) {
	int m = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			m = m * 10 + a[i][j];
		}
	return m;
}
void func(int x, int y, int m) {
	q.push({ {x,y}, m });
	visit.insert({ m, 1 });
	while (!q.empty()) {
		pair<pair<int, int>, int>  t = q.front(); q.pop();
		if (t.second == 123456780) {
			printf("%d\n", visit[t.second]-1);
			return;
		}
		for (int i = 0, tx, ty; i < 4; i++) {
			tx = t.first.first + dx[i], ty = t.first.second + dy[i];
			if (safe(tx, ty)) {
				int m_a[3][3], tm = t.second;
				for (int j = 2; j >= 0; j--)
					for (int k = 2; k >= 0; k--) {
						m_a[j][k] = tm % 10;
						tm /= 10;
					}
				swap(m_a[ty][tx], m_a[t.first.second][t.first.first]);
				tm = make_int(m_a);
				if (!visit.count(tm)) {
					visit.insert({ tm, visit[t.second]+1});
					q.push({ {tx, ty}, tm });
				}
			}
		}
	}
	printf("-1\n");
	return;
}
int main() {
	int x, y, m =0, m_a[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			scanf("%d", &m_a[i][j]);
			if (!m_a[i][j]) x = j, y = i;
			m = m * 10 + m_a[i][j];
		}
	func(x, y, m);
	return 0;
}