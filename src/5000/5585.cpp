#include<cstdio>
int m[6] = { 500,100,50,10,5,1 };
int main() {
	int a, ret=0;
	scanf("%d", &a);
	a = 1000 - a;
	for (int i = 0; i < 6; i++) {
		ret += (a / m[i]);
		a %= m[i];
	}
	printf("%d", ret);
	return 0;
}