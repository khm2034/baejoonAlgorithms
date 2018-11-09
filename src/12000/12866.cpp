#include<cstdio>
#define MOD 1000000007
int N, a[26];
long long ret = 1;
int main() {
	scanf("%d", &N);
	while (N--) {
		char c;
		scanf(" %c", &c);
		a[c - 'A']++;
	}
	ret = (ret*a[0]) % MOD;
	ret = (ret*a[2]) % MOD;
	ret = (ret*a[6]) % MOD;
	ret = (ret*a[19]) % MOD;
	printf("%lld", ret);
	return 0;
}