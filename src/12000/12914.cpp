#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int N, D;
vector<pii> v;
int main() {
	scanf("%d%d", &N, &D);
	for (int i = 0, t; i < N; i++) {
		scanf("%d", &t);
		for (int j = 0; j < v.size(); j++) {
			if (t >= v[j].first && t <= v[j].second) {
				t = v[j].second + 1;
				continue;
			}
			if (t < v[j].first) break;
		}
		printf("%d ", t);
		v.push_back({ t - D+1, t + D-1 });
		sort(v.begin(), v.end());
	}
	return 0;
}