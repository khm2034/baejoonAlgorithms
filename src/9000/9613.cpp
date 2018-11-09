#include<cstdio>
int T, N, a[101];
int gcd(int a, int b) {return !b ? a : gcd(b, a%b);}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d", &a[i]);
		long long ret = 0;
		for (int i = 0; i < N - 1; i++) for (int j = i + 1; j < N; j++)
			ret += a[i] > a[j] ? gcd(a[i], a[j]) : gcd(a[j], a[i]);
		printf("%lld\n", ret);
	}
	return 0;
}