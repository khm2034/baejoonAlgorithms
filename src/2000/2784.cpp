#include<cstdio>
#include<cstring>
char m[4][4], s[6][4];
bool func(int v, int c) {
	if (c == 3) {
		int t = 0, chk = 0;
		for (int i = 0; i < 6; i++) {
			if (v & (1 << i)) continue;
			for (int j = 0; j < 3; j++) {
				if (chk&(1 << j)) continue;
				if (m[0][j] == s[i][0] && m[1][j] == s[i][1] && m[2][j] == s[i][2]) {
					t++, chk |= (1 << j);
					break;
				}
			}
		}
		if (t == 3) return true;
		return false;
	}
	for (int i = 0; i < 6; i++) {
		if (v & (1 << i)) continue;
		strcpy(m[c], s[i]);
		if (func(v | (1 << i), c + 1)) return true;
	}
	return false;
}
int main() {
	for (int i = 0; i < 6; i++) scanf("%s", s[i]);
	if (func(0, 0)) for (int i = 0; i < 3; i++) printf("%s\n", m[i]);
	else printf("0");
	return 0;
}