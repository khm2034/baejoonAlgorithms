#include<iostream>
#include<queue>
using namespace std;
int T, a, b, p[10001];
void bfs() {
	queue<int> q;
	int v[10001] = { 0 };
	v[a] = 1;
	q.push(a);
	while (!q.empty()) {
		int t = q.front(); q.pop();
		if (t == b) {
			printf("%d\n", v[t]-1);
			return;
		}
		int k = 1;
		for (int i = 0; i < 4; i++, k = k * 10) {
			int tmp = t-(((t / k) % 10)*k);
			for (int j = 0, m ; j<10; j++) {
				m = k * j;
				if (tmp+m > 1000 && !p[tmp + m] && !v[tmp + m]) {
					v[tmp + m] = v[t] + 1;
					q.push(tmp + m);
				}
			}
		}
	}
	printf("Impossible\n");
}
int main() {
	for (int i = 2; i <= 100; i++) for (int j = i * 2; j <= 10000; j += i) p[j] = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &a, &b);
		bfs();
	}
	return 0;
}