#include<cstdio>
int a[7], mx, ret;
int main() {
	for (int i = 0, t; i < 3; i++) {
		scanf("%d", &t);
		a[t]++;
	}
	for (int i = 1; i < 7; i++) {
		if (a[i] == 2) ret = 1000 + i * 100;
		if (a[i] == 3) ret = 10000 + i * 1000;
		if (a[i] == 1) mx = i;
	}
	printf("%d", ret? ret : mx*100);
	return 0;
}