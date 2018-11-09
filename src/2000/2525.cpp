#include<cstdio>
int main() {
	int t, m, cm;
	scanf("%d%d%d", &t, &m, &cm);
	cm += m;
	t = (t + cm / 60) % 24;
	cm %= 60;
	printf("%d %d", t, cm);
	return 0;
}