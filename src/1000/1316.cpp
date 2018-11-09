#include<cstdio>
int N, ret;
int main() {
	scanf("%d", &N);
	while (N--) {
		bool v[26] = { 0 }, f = true;
		char s[101], pre=0;
		scanf(" %s", s);
		for (int i = 0; f && s[i]; i++) {
			if (pre != s[i] && v[s[i] - 'a']) f = !f;
			else {
				pre = s[i];
				v[s[i] - 'a'] = true;
			}
		}
		if (f) ret++;
	}
	printf("%d", ret);
	return 0;
}