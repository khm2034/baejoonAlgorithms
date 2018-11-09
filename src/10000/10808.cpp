#include<cstdio>

char s[105];
int cnt[26];
int main(){
	scanf("%s", s);
	for (int i = 0; s[i]; i++) cnt[s[i] - 'a']++;
	for (int i = 0; i < 26; i++) printf("%d ", cnt[i]);
	return 0;
}