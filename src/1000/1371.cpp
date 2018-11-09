#include<cstdio>
int cnt[26];
char s[1000000];
int main(){
	freopen("input.txt", "r", stdin);
	char c;
	for (int i = 0; s[i]; i++) printf("%c", s[i]);
	while (scanf("%c", &c) != EOF){
		if (c >= 'a' && c <= 'z')
			++cnt[c - 'a'];
	}
	int max = cnt[0];
	for (int i = 1; i < 26; ++i)
		if (max < cnt[i]) max = cnt[i];
	for (int i = 0; i < 26; ++i)
		if (cnt[i] == max)
			printf("%c", i + 'a');
	return 0;
}