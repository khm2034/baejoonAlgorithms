#include<cstdio>
char s[10001];
int ret, t;
int main() {
	while (scanf("%s", s) != EOF) {
		for (int i = 0; s[i]; i++) {
			if (s[i] == ',') ret += t, t = 0;
			else t = t * 10 + s[i] - '0';
		}
	}
	printf("%d", ret+t);
	return 0;
}