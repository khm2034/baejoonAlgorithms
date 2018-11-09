#include<cstdio>
int main() {
	int k, n, m;
	scanf("%d%d%d", &k, &n, &m);
	int ret = n * k - m;
	printf("%d", ret>0?ret:0);
	return 0;
}