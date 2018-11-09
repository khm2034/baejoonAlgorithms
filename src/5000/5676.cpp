#include<cstdio>
int N, K, seg[(int)1e5*5 + 5];
int query(int le, int ri, int x, int y, int node) {
	if (ri < x || le > y) return 1;
	if (le <= x && y <= ri) return seg[node];
	int mid = (x + y) / 2;
	return query(le, ri, x, mid, node * 2)*query(le, ri, mid + 1, y, node * 2 + 1);
}
int update(int pos, int x, int y, int node, int val) {
	if (pos < x || pos > y) return seg[node];
	if (x == y) {
		val > 0 ? seg[node] = 1 : val < 0 ? seg[node] = -1 : seg[node] = 0;
		return seg[node];
	}
	int mid = (x + y) / 2;
	return seg[node] = update(pos, x, mid, node * 2, val) * update(pos, mid + 1, y, node * 2 + 1, val);
}
int main() {
	while (scanf("%d%d", &N, &K) != EOF) {
		for (int i = 0, t; i < N; i++) {
			scanf("%d", &t);
			update(i, 0, N - 1, 1, t);
		}
		char c;
		for (int i = 0, a, b; i < K; i++) {
			scanf(" %c %d %d", &c, &a, &b);
			if (c == 'C') update(a - 1, 0, N - 1, 1, b);
			else {
				int t = query(a-1, b-1, 0, N-1, 1);
				t > 0 ? printf("+") : t<0 ? printf("-") : printf("0");
			}
		}
		printf("\n");
	}
	return 0;
}