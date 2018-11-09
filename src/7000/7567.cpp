#include<cstdio>
char c, pre;
int ret;
int main() {
	while (scanf(" %c", &c) != EOF) {
		if (!pre || pre != c) ret += 10, pre=c;
		else ret += 5;
	}
	printf("%d", ret);
	return 0;
}