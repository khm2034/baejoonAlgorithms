#include<iostream>
using namespace std;
typedef long long ll;

int N, M;
ll arr[100001];
int main(){
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);
	ll le = 0, ri = 1e18, mid, cnt, ret=1e18;
	while (le <= ri) {
		mid = (le + ri) / 2;
		cnt = 0;
		for (int i = 0; i < N; i++) cnt += mid / arr[i];
		if (cnt >= M) {
			if (ret > mid) ret = mid;
			ri = mid - 1;
		}
		else le = mid + 1;
	}
	printf("%lld\n", ret);
	return 0;
}