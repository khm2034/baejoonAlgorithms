#include<iostream>
#define MOD 100000000000000llu
using namespace std;
typedef unsigned long long ull;
pair<ull, ull> dp[101][101], result;
ull n, m;
pair<ull, ull> func(ull n, ull m) {
	if (n == m || !m) return { 0llu, 1llu };
	if (m == 1) return { 0llu, n };
	pair<ull, ull> &ret = dp[n][m];
	if (ret.first || ret.second) return ret;
	return ret = { func(n - 1,m).first + func(n - 1, m - 1).first + ((func(n - 1, m).second + func(n - 1, m - 1).second)/MOD),
		(func(n - 1, m).second%MOD + func(n - 1, m - 1).second%MOD)%MOD };
}
int main() {
	scanf("%llu%llu", &n, &m);
	result = func(n, m);
	if (result.first) {
		printf("%llu", result.first);
		for (ull i = MOD / 10; i >= 0; i /= 10) {
			if (result.second / i) break;
			else printf("0");
		}
	}
	printf("%llu\n", result.second);
	return 0;
}