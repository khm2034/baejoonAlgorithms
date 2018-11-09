#include<cstdio>
int t, n, p[100001];
int main() {
	for (int i = 2; i*i < 100001; i++) for (int j = i * 2; j < 100001; j += i) p[j] = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 2; n!=1 && i < 100001; i++) {
			if (p[i]) continue;
			int c = 0;
			while (1) {
				if (n%i) break;
				c++;
				n /= i;
			}
			if(c) printf("%d %d\n", i, c);
		}
	}
	return 0;
}