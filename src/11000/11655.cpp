#include<cstdio>
char s[105];
int main() {
	scanf("%[^\n]s", s);
	for (int i = 0; s[i]; i++)
		if (s[i] >= 'a' && s[i] <= 'z') printf("%c", s[i] + 13 > 'z' ? s[i] - 13 : s[i]+13);
		else if (s[i] >= 'A' && s[i] <= 'Z') printf("%c", s[i] + 13 > 'Z' ? s[i] - 13 : s[i] + 13);
		else printf("%c", s[i]);
	return 0;
}