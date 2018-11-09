#include<cstdio>
int S, P, p_c[26], s_c[26], ret;
char s[1000001];
int chk() {
	for (int i = 0; i < 26; i++) if (p_c[i] > s_c[i]) return 0;
	return 1;
}
int main() {
	scanf("%d%d", &S, &P);
	scanf(" %s", s);
	scanf("%d%d%d%d", &p_c[0], &p_c[2], &p_c[6], &p_c[19]);
	for (int i = 0; i < P; i++) s_c[s[i] - 'A']++;
	ret += chk();
	for (int i = P; i < S; i++) {
		s_c[s[i-P] - 'A']--;
		s_c[s[i] - 'A']++;
		ret += chk();
	}
	printf("%d", ret);
	return 0;
}