#include<cstdio>
#include<queue>
int N, M;
std::queue<int> q;
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) q.push(i);
	printf("<");
	while (q.size() != 1) {
		for (int i = 0; i < M - 1; i++) {
			q.push(q.front()); q.pop();
		}
		printf("%d, ", q.front());
		q.pop();
	}
	printf("%d>", q.front());
	return 0;
}