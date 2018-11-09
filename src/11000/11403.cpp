#include<iostream>
#include<queue>
using namespace std;
int N, map[101][101], ans[101][101];
queue<int> q;
void bfs(int n) {
	bool visit[101] = { false };
	q.push(n);
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int i = 0; i < N; i++) {
			if (!visit[i] && map[t][i]) {
				visit[i] = true;
				ans[n][i] = 1;
				q.push(i);
			}
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &map[i][j]);
	for (int i = 0; i < N; i++) bfs(i);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}