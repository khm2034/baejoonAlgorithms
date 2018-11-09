#include<iostream>
#include<queue>
using namespace std;
int F, S, G, U, D, visit[1000001];
queue<int> q;
void bfs() {
	visit[S] = 1;
	q.push(S);
	while (!q.empty()) {
		int t = q.front(); q.pop();
		if (t == G) {
			printf("%d\n", visit[t] - 1);
			return;
		}
		if (t + U <= F && !visit[t + U]) {
			visit[t + U] = visit[t] + 1;
			q.push(t + U);
		}
		if (t - D > 0 && !visit[t - D]) {
			visit[t - D] = visit[t] + 1;
			q.push(t - D);
		}
	}
	printf("use the stairs\n");
}
int main() {
	scanf("%d%d%d%d%d", &F, &S, &G, &U, &D);
	bfs();
	return 0;
}