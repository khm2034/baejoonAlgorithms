#include<cstdio>
#include<queue>
struct doc { int i, p; };
int T, N, M;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		std::queue<doc> q;
		std::priority_queue<int> pq;
		for (int i = 0, t; i < N; i++) {
			scanf("%d", &t);
			q.push({ i,t });
			pq.push(t);
		}
		for(int i=1;;){
			doc t = q.front(); q.pop();
			if (t.p < pq.top()) q.push(t);
			else if (t.i == M) {
				printf("%d\n", i);
				break;
			}
			else {
				pq.pop();
				i++;
			}
		}
	}
	return 0;
}
