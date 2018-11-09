#include<cstdio>
char s[2501];
int mx, c[4], f;
int func(int idx) {
	for (int i = 1; i < idx; i++) if (!c[i-1] || c[i-1] < c[i]) return 1;
	if (idx && (!c[idx - 1] || c[idx - 1] <= c[idx])) return 1;
	c[idx]++;
	mx = mx>c[idx]?mx:c[idx];
	return 0;
}
int main() {
	scanf("%s", s);
	for (int i = 0; !f&& s[i]; i++) {
		if (s[i] == 'q') f = func(0);
		if (s[i] == 'u') f = func(1);
		if (s[i] == 'a') f = func(2);
		if (s[i] == 'c') f = func(3);
		if (s[i] == 'k') {
			for (int i = 0; i < 4; i++) {
				if (!c[i]) f = 1;
				else c[i]--;
			}
		}
	}
	for (int i = 0; !f&&i < 4; i++) if (c[i]) f = 1;
	if (!f) printf("%d", mx);
	else printf("-1");
	return 0;
}