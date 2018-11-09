#include<cstdio>
#define min(a, b) a < b ? a : b
int N, M, c = 100, mi;
bool arr[10];
void func(int ch, int cnt) {
	if (cnt >= mi) return;
	if (ch > 1000000) return;
	if (N >= ch) mi = min(mi, N-ch+cnt);
	else mi = min(mi, ch - N + cnt);
	for (int i = 0; i < 10; i++) {
		if (arr[i] || (!ch && !i)) continue;
		func(ch * 10 + i, cnt + 1);
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0, t; i < M; i++) {
		scanf("%d", &t);
		arr[t] = true;
	}
	if (N >= 100) mi = N - 100;
	else mi = 100 - N;
	for (int i = 0; i < 10; i++) {
		if (arr[i]) continue;
		func(i, 1);
	}
	printf("%d\n", mi);
	return 0;
}