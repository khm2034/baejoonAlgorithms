#include<cstdio>
#include<algorithm>
using namespace std;
pair<int, int> pv[100001];
int N, D, mi, mx;
long long ret, t;
int main() {
	scanf("%d%d", &N, &D);
	for (int i = 0; i < N; i++) scanf("%d%d", &pv[i].first, &pv[i].second);
	sort(pv, pv + N);
	while(mx < N) {
		if (pv[mx].first - pv[mi].first < D) {
			t += pv[mx].second;
			ret = max(t, ret);
			mx++;
		}
		else {
			t -= pv[mi].second;
			mi++;
		}
	}
	printf("%lld", ret);
	return 0;
}