#include<cstdio>
int n;
long long ret;
int main() {
	scanf("%d", &n);
	ret = 2;
	for (int i = 0; i < n; i++) ret += (ret - 1);
	printf("%lld", ret*ret);
	return 0;
}