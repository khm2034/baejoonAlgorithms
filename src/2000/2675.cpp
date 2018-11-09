#include<cstdio>
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int r;
		char s[21];
		scanf("%d %s", &r, s);
		for (int i = 0; s[i]; i++) for (int j = 0; j < r; j++) printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}