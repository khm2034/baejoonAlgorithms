#include<cstdio>
char s[105];
int cnt[4];
int main() {
	freopen("input.txt", "r", stdin);
	while (scanf("%[^\n]s", s) != EOF) {
		for (int i = 0; s[i]; i++) {
			if (s[i] >= 'a' && s[i] <= 'z') cnt[0]++;
			else if (s[i] >= 'A' && s[i] <= 'Z') cnt[1]++;
			else if (s[i] >= '0' && s[i] <= '9') cnt[2]++;
			else cnt[3]++;
		}
		for (int i = 0; i < 4; i++) {
			printf("%d ", cnt[i]);
			cnt[i] = 0;
		}
		printf("\n");
		getchar();
	}
	return 0;
}