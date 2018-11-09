#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int N, v[2][100001];
vector<int> vec[100001];
int bfs(int n, int c) {
	int mx=0;
	queue<int> q;
	q.push(n);
	v[c][n] = 1;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int i : vec[t]) {
			if (v[c][i]) continue;
			v[c][i] = v[c][t] + 1;
			q.push(i);
		}
	}
	for (int i = 1; i <= N; i++) if (v[c][mx] < v[c][i]) mx = i;
	return mx;
}
int main() {
	scanf("%d", &N);
	for (int i = 0, a, b; i < N - 1; i++) {
		scanf("%d%d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	printf("%d", v[1][bfs(bfs(1, 0), 1)] /2);
	return 0;
}