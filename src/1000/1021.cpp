#include<cstdio>
#include<deque>
std::deque<int> dq;
int N, M, t, ret;
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) dq.push_back(i);
	while (M--) {
		scanf("%d", &t);
		int f, b;
		for (f = 0; f < N; f++) if (dq[f] == t) break;
		b = dq.size() - f;
		if (f < b) {
			ret += f;
			for (int i = 0; i < f; i++) {
				dq.push_back(dq.front()); dq.pop_front();
			}
		}
		else {
			ret += b;
			for (int i = 0; i < b; i++) {
				dq.push_front(dq.back()); dq.pop_back();
			}
		}
		dq.pop_front();
	}
	printf("%d", ret);
	return 0;
}