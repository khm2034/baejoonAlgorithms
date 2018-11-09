#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int N, arr[9], t[9], ret;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	sort(arr, arr + N);
	do {
		int sum = 0;
		for (int i = 0; i < N - 1; i++) sum += abs(arr[i] - arr[i + 1]);
		ret = max(ret, sum);
	} while (next_permutation(arr, arr + N));
	printf("%d\n", ret);
	return 0;
}