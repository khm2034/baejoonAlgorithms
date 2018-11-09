#include<cstdio>
#define max(a,b) (a>b?a:b)
int N, ret;
int main() {
	scanf("%d", &N);
	while (N--) {
		int a[7] = { 0 }, mx = 0, tm=0;
		for (int i = 0, t; i < 3; i++) {
			scanf("%d", &t);
			a[t]++;
		}
		for (int i = 1; i < 7; i++) {
			if (a[i] == 2) tm = 1000 + i * 100;
			if (a[i] == 3) tm = 10000 + i * 1000;
			if (a[i] == 1) mx = i;
		}
		ret = max(ret, max(tm, mx * 100));
	}
	printf("%d", ret);
	return 0;
}