#include<cstdio>
#include<queue>
int N;
std::queue<int> q;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) q.push(i);
	for (int i = 0, t; i < N - 1; i++) {
		printf("%d ",q.front()); q.pop();
		q.push(q.front()); q.pop();
	}
	printf("%d", q.front());
	return 0;
}