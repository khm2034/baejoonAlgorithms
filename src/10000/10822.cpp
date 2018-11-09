#include<cstdio>
int ret, t;
int main() {
	while (scanf("%d,", &t) != EOF) ret += t;
	printf("%d", ret);
	return 0;
}