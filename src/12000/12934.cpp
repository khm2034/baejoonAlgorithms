#include<cstdio>
#include<cmath>
typedef long long ll;
ll x, y, n, t, c;
int main() {
	scanf("%lld%lld", &x, &y);
	n = sqrt((x + y) * 2) - 1;
	while (1) {
		n++;
		t = (n*(n + 1)) / 2;
		if (t == x + y) break;
		else if (t > x + y) {
			printf("-1");
			return 0;
		}
	}
	while (1) {
		if (!x) break;
		c++;
		if (x > n) {
			x -= n;
			n--;
		}
		else break;
	}
	printf("%lld", c);
	return 0;
}