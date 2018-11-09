#include<cstdio>
#include<algorithm>
using namespace std;
struct p { int x, y; };
int N;
long long mi = 4e9 + 5, sum, t;
p a[100001];
int dis(p a, p b) { return abs(a.x - b.x) + abs(a.y - b.y); };
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d%d", &a[i].x, &a[i].y);
	for (int i = 1; i < N; i++) sum += dis(a[i], a[i - 1]);
	for (int i = 1; i < N - 1; i++) {
		t = sum - dis(a[i], a[i - 1]) - dis(a[i], a[i + 1]) + dis(a[i - 1], a[i + 1]);
		mi = min(mi, t);
	}
	printf("%lld", mi);
	return 0;
}