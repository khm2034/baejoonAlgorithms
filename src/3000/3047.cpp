#include<cstdio>
#include<algorithm>
int main() {
	int a[3];
	char s[4];
	scanf("%d%d%d %s", &a[0], &a[1], &a[2], s);
	std::sort(a, a + 3);
	for (int i = 0; i < 3; i++) {
		if (s[i] == 'A') printf("%d ", a[0]);
		if (s[i] == 'B') printf("%d ", a[1]);
		if (s[i] == 'C') printf("%d ", a[2]);
	}
	return 0;
}