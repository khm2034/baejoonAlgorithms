#include<cstdio>
int y[2], m[2], d[2];
int main() {
	for (int i = 0; i < 2; i++) scanf("%d%d%d", &y[i], &m[i], &d[i]);
	if (y[0] == y[1]) printf("0\n1\n0");
	else {
		int a = y[1] - y[0];
		if (m[0] < m[1]) printf("%d\n%d\n%d", a, a+1, a);
		else if (m[0] > m[1]) printf("%d\n%d\n%d", a - 1, a+1, a);
		else{
			if (d[0] < d[1]) printf("%d\n%d\n%d", a, a + 1, a);
			else if (d[0] > d[1]) printf("%d\n%d\n%d", a - 1, a + 1, a);
			else printf("%d\n%d\n%d", a, a+1, a);
		}
	}
	return 0;
}