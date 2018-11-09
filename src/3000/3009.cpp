#include<cstdio>
int x[1001], y[1001], tx[3], ty[3],rx,ry;
int main() {
	for (int i = 0, tx, ty; i < 3; i++) {
		scanf("%d%d", &tx, &ty);
		::tx[i] = tx, ::ty[i] = ty;
		x[tx]++, y[ty]++;
	}
	for (int i = 0; i < 3; i++) {
		if (x[tx[i]] == 1) rx = tx[i];
		if (y[ty[i]] == 1) ry = ty[i];
	}
	printf("%d %d", rx, ry);
	return 0;
}