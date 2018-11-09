#include<iostream>
#include<vector>
#include<algorithm>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppii;
int N, K, R=0, s=1;
vector<ppii> vec;
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0, n,g, s, b; i < N; i++) {
		scanf("%d%d%d%d", &n, &g, &s, &b);
		vec.push_back({ {g, s}, {b, n} });
	}
	sort(vec.begin(), vec.end());
	ppii pre, now;
	for (int i = vec.size()-1; i >= 0; i--) {
		now = vec[i];
		if (pre.fi.fi == now.fi.first &&
			pre.fi.se == now.fi.se &&
			pre.se.fi == now.se.fi) s++;
		else {
			R += s;
			s = 1;
		}
		if (now.se.se == K) break;
		pre = now;
	}
	printf("%d", R);
}