#include<cstdio>
#include<algorithm>
int N, a[41], ani[2][41], c[2], ret;
void func(int idx) {
	if (idx == N) {
		ret++;
		return;
	}
	for(int i=0; i<2; i++) if ((!c[i] && !a[idx]) || (c[i] && a[idx] == ani[i][c[i] - 1] + 1)) {
		ani[i][c[i]++] = a[idx];
		func(idx + 1);
		c[i]--;
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	std::sort(a, a + N);
	func(0);
	printf("%d", ret);
	return 0;
}