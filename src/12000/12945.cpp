#include<cstdio>
#include<algorithm>
int N, V[500001], cnt;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &V[i]);
	std::sort(V, V + N);
	for (int i = 0, j=0, c = 0; i < N; i++) {
		for (; j < i; j++, c++) if (V[j] * 2 > V[i]) break;
		if (cnt < N/2 && cnt <= i/2 && cnt < c) cnt++;
	}
	printf("%d", N-cnt);
	return 0;
}