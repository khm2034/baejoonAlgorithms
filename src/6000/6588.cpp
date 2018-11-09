#include<cstdio>
int n;
bool d[1000001];
int main() {
	for (int i = 2; i*i <= 1000001; i++) 
		for (int j = i * 2; j <= 1000001; j += i)
			d[j] = true;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		bool f = true;
		for (int i = 3; f && i * 2 <= n; i += 2) {
			if (d[i]) continue;
			if (!d[n - i]) {
				printf("%d = %d + %d\n", n, i, n - i);
				f = !f;
			}
		}
		if (f) printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}