#include<cstdio>
int N, a[2001], t;
int main() {
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &t);
		a[t + 1000]++;
	}
	for (int i = 0; i < 2001; i++)
		if (a[i]) printf("%d ", i - 1000);
	return 0;
}