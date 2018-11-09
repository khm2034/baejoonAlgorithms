#include<cstdio>
#define p(n) (1<<(n))
int N, r, c, cnt;
bool f(int n, int sx, int sy) {
	int tx = sx + p(n), ty = sy + p(n);
	if (n == 1) {
		if (r >= sy && r <= ty-1 && c >= sx && c <= tx-1) {
			if (r == sy) {
				if (c != sx) cnt += 1;
			}
			else {
				if (c == sx) cnt += 2;
				else cnt += 3;
			}
			return true;
		}
		cnt += 4;
		return false;
	}
	if (r >= sy && r <= ty-1 && c >= sx && c <= tx-1) {
		if (f(n - 1, sx, sy)) return true;
		if (f(n - 1, sx + p(n-1), sy)) return true;
		if (f(n - 1, sx, sy + p(n - 1))) return true;
		if (f(n - 1, sx + p(n - 1), sy + p(n - 1))) return true;
	}
	cnt += ((1 << n)*(1<<n));
	return false;
}
int main() {
	scanf("%d%d%d", &N, &r, &c);
	f(N,0,0);
	printf("%d", cnt);
	return 0;
}