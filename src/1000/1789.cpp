#include<cstdio>
typedef long long ll;
int main() {
	ll N, sum = 0, i;
	scanf("%lld", &N);
	for (i = 1; i <= N*2; i++) {
		sum += i;
		if (sum > N) {
			printf("%lld\n", i - 1);
			break;
		}
	}
	return 0;
}