#include<cstdio>
int h, m;
int main() {
	scanf("%d%d", &h, &m);
	if (m >= 45) m -= 45;
	else {
		if (--h < 0) h = 23;
		m += 15;
	}
	printf("%d %d", h, m);
	return 0;
}