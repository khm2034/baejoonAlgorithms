#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T, N, a[2][1001];
long long cnt;
vector<int> vec[2];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < 2; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) scanf("%d", &a[i][j]);
		for (int j = 0, sum = 0; j < N; j++, sum=0) {
			for (int k = j; k < N; k++) {
				sum += a[i][k];
				vec[i].push_back(sum);
			}
		}
	}
	for (int i = 0; i < 2; i++) sort(vec[i].begin(), vec[i].end());
	for (auto v : vec[0]) {
		int up = upper_bound(vec[1].begin(), vec[1].end(), T - v) - vec[1].begin();
		int lo = lower_bound(vec[1].begin(), vec[1].end(), T - v) - vec[1].begin();
		cnt += up - lo;
	}
	printf("%lld", cnt);
	return 0;
}