#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int v[2001], N, M, cnt;
vector<int> vec[2001];
bool bfs(int n) {
	queue<int> q;
	v[n] = 1;
	q.push(n);
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int i : vec[t]) {
			if (v[i]) {
				if (v[i] == v[t]) return false;
			}
			else {
				v[i] = -v[t];
				q.push(i);
			}
		}
	}
	return true;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0, a, b; i < M; i++) {
		scanf("%d%d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	bool f = true;
	for (int i = 1; f&&i <= N; i++) {
		if (v[i]) continue;
		f = bfs(i);
	}
	printf("%d", f);
	return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//int N, M, p[2005], enemy[2005];
//
//int find(int x) {
//	if (x == -1 || p[x] == x)    return x;
//	return p[x] = find(p[x]);
//}
//
//void makeEnemy(int u, int v) {
//	u = find(u), v = find(v);
//	int x = find(enemy[u]), y = find(enemy[v]);
//	if (x != -1) p[x] = v;
//	if (y != -1) p[y] = u;
//	enemy[u] = v;
//	enemy[v] = u;
//}
//
//int main() {
//	scanf("%d %d", &N, &M);
//	for (int i = 1; i <= N; i++)	p[i] = i, enemy[i] = -1;
//	int ans = 1;
//	for (int i = 0; i < M; i++) {
//		int u, v;
//		scanf("%d %d", &u, &v);
//		if (find(u) == find(v)) {
//			ans = 0;
//			break;
//		}
//		makeEnemy(u, v);
//	}
//	printf("%d\n", ans);
//	return 0;
//}