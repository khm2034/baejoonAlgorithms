#include<cstdio>
char s[2000000];
int ret;
int main() {
	scanf("%s", s);
	if (s[0] == '0') {
		if (s[1] == 'x') {
			for (int i = 2; s[i]; i++) {
				if (s[i] >= 'a') ret = ret * 16 + s[i] - 'a' + 10;
				else ret = ret * 16 + s[i] - '0';
			}
		}
		else 
			for (int i = 1; s[i]; i++) ret = ret * 8 + s[i] - '0';
		printf("%d", ret);
	}
	else printf("%s", s);
	return 0;
}