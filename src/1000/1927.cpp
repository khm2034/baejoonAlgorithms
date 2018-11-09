#include<cstdio>
#include<queue>
#include<functional>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int N;
int main() {
	scanf("%d", &N);
	for (int i = 0, t; i < N; i++) {
		scanf("%d", &t);
		if (!t) {
			if (pq.empty()) printf("0\n");
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else pq.push(t);
	}
	return 0;
}