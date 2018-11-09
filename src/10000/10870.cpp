#include<cstdio>
int fibo[100] = { 0,1 }, n;
int main() {
	scanf("%d", &n);
	if (n <= 1) printf("%d\n", n);
	else {
		for (int i = 2; i <= n; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];
		printf("%d\n", fibo[n]);
	}
	return 0;
}