#include<cstdio>
#include<memory.h>
char s[105];
int cnt[26];
int main()
{
	scanf("%s", s);
	memset(cnt, -1, sizeof(cnt));
	for (int i = 0; s[i]; i++)
		if (cnt[s[i] - 'a'] == -1)
			cnt[s[i] - 'a'] = i;
	for (int i = 0; i < 26; i++)
		printf("%d ", cnt[i]);
	return 0;
}