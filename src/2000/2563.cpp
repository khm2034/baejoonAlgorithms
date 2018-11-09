#include<cstdio>
int m[1001][1001], N, x, y, c;
int main() {
	scanf("%d", &N);
	while (N--) {
		scanf("%d%d", &x, &y);
		for (int i = y; i < y + 10; i++) for (int j = x; j < x + 10; j++) m[i][j] = 1;
	}
	for (int i = 0; i < 1001; i++) for (int j = 0; j < 1001; j++) if (m[i][j])c++;
	printf("%d", c);
	return 0;
}