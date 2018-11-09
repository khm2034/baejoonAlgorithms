#include<cstdio>
#include<queue>
using namespace std;
int N, D, mx;
char g[51][51];
bool bfs(int s) {
	int v[51] = { 0 };
	queue<int> q;
	q.push(s);
	v[s] = 1;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int i = 0; i < N; i++) {
			if (!v[i] && g[t][i] == 'Y') {
				v[i] = v[t] + 1;
				mx = mx < v[i] ? v[i] : mx;
				q.push(i);
			}
		}
	}
	if (mx == 1) return false;
	for (int i = 0; i < N; i++) if (!v[i]) return false;
	return true;
}
int main() {
	scanf("%d%d", &N, &D);
	for (int i = 0; i < N; i++) scanf(" %s", g[i]);
	for(int i=0; i<N; i++)
		if (!bfs(i)) {
			printf("-1");
			return 0;
		}
	printf("%d", (mx - 1)*D);
	return 0;
}