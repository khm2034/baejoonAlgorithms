#include<cstdio>
typedef long long ll;
ll a, b, c;
ll func(ll a, ll b) {
	if (b == 0) return 1;
	if (b & 1) {
		return ((func(a, b - 1)%c)*(a%c) % c);
	}
	else {
		ll ret = func(a, b / 2) % c;
		return (ret*ret) % c;
	}
}
int main() {
	scanf("%lld%lld%lld", &a, &b, &c);
	printf("%lld\n", func(a, b)%c);
	return 0;
}