#include<iostream>
#include<queue>
using namespace std;
int S, visit[2001][2001];
queue<pair<int, int>> q;
pair<int, int> func1(pair<int, int> a) { return { a.first, a.first }; }
pair<int, int> func2(pair<int, int> a) { return { a.first + a.second, a.second }; }
pair<int, int> func3(pair<int, int> a) { return { a.first - 1, a.second }; }
pair<int, int>(*f[3])(pair<int, int>) = { func1, func2, func3 };
void bfs() {
	q.push({ 1, 0 });
	visit[1][0] = 1;
	while (!q.empty()) {
		pair<int, int> t = q.front(); q.pop();
		if (t.first == S) {
			printf("%d\n", visit[t.first][t.second]-1);
			return;
		}
		for (int i = 0; i < 3; i++) {
			pair<int, int> ta = f[i](t);
			if (ta.first >= 0 && ta.first<=2000 && !visit[ta.first][ta.second]) {
				visit[ta.first][ta.second] = visit[t.first][t.second]+1;
				q.push(ta);
			}
		}
	}
}
int main() {
	scanf("%d", &S);
	bfs();
	return 0;
}