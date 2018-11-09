#include<stdio.h>
#define max(a, b) a>b?a:b
int N, mx, t[16], p[16];
void solution(int idx, int c) {
	if (idx > N) return;
	for (int i = idx; i < N; i++) 
		solution(i + t[i], c + p[i]);
	mx = max(mx, c);
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &t[i], &p[i]);
	solution(0, 0);
	printf("%d\n", mx);
	return 0;
}
