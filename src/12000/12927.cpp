#include<cstdio>
char s[2001];
int ret;
int main() {
	scanf("%s", &s[1]);
	for (int i = 1; s[i]; i++) {
		if (s[i] == 'N') continue;
		ret++;
		for (int j = i; s[j]; j += i) s[j] = (s[j] == 'Y' ? 'N' : 'Y');
	}
	for (int i = 1; s[i]; i++) if (s[i] == 'Y') {
		printf("-1");
		return 0;
	}
	printf("%d", ret);
	return 0;
}