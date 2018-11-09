#include<cstdio>
int N, B, C, a[1000001];
long long ret;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	scanf("%d%d", &B, &C);
	for (int i = 0; i < N; i++) {
		ret++;
		if (a[i] - B > 0) ret += (a[i] - B -1) / C + 1;
	}
	printf("%lld", ret);
	return 0;
}