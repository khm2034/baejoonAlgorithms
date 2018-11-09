#include<cstdio>
int a, b;
int gcd(int a, int b) {return !b?a:gcd(b, a%b);}
int main() {
	scanf("%d%d", &a, &b);
	int g = a > b ? gcd(a, b) : gcd(b, a);
	printf("%d\n%d", g, a*b / g);
	return 0;
}