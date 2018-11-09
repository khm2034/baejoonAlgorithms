#include<cstdio>
int N, M, psum[302][302],K;
int main() {
	scanf("%d%d", &N, &M); 
	for(int i=1, t; i<=N; i++)
		for (int j = 1; j <= M; j++) {
			scanf("%d", &t);
			psum[i][j] = t + psum[i][j - 1] + psum[i - 1][j] - psum[i - 1][j - 1];
		}
	scanf("%d", &K);
	while (K--) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d\n", psum[c][d] - psum[a-1][d] - psum[c][b-1] + psum[a-1][b-1]);
	}
}