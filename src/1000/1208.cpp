#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, S, arr[41];
long long cnt;
vector<int> vec[2];
int main() {
	scanf("%d%d", &N, &S);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	for (int i = 0, sum = 0; i < (1 << N / 2); i++, sum = 0) {
		for (int j = 0; j < N / 2; j++)
			if (i & (1 << j))
				sum += arr[j];
		vec[0].push_back(sum);
	}
	for (int i = 0, sum = 0; i < (1 << (N-(N / 2))); i++, sum = 0) {
		for (int j = N/2; j < N; j++)
			if (i & (1 << (j-N/2)))
				sum += arr[j];
		vec[1].push_back(sum);
	}
	for (int i = 0; i < 2; i++) sort(vec[i].begin(), vec[i].end());
	for (auto v : vec[0]) {
		int up = upper_bound(vec[1].begin(), vec[1].end(), S-v) - vec[1].begin();
		int lo = lower_bound(vec[1].begin(), vec[1].end(), S-v) - vec[1].begin();
		cnt += up - lo;
	}
	if (!S) cnt--;
	printf("%lld", cnt);	
	return 0;
}