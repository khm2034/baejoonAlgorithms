#include<cstdio>
#include<memory.h>
int rect[4][4], mi = 9;
int ret[8][3], tmp[8][3];
void shift(int ty, int a) {
	if (!ty) {
		int t = rect[a][3];
		for (int i = 2; i >= 0; i--) rect[a][i + 1] = rect[a][i];
		rect[a][0] = t;
	}
	else {
		int t = rect[3][a];
		for (int i = 2; i >= 0; i--) rect[i + 1][a] = rect[i][a];
		rect[0][a] = t;
	}
}
int chk() {
	int t = 1, ret = 0;
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) if (rect[i][j] == t++) ret++;
	return ret;
}
void func(int c) {
	if (c >= mi || c == 8) return;
	int cnt = chk();
	if (cnt == 16) {
		memcpy(ret, tmp, sizeof(ret));
		mi = c;
		return;
	}
	if (c + 2 >= mi && cnt < 12) return;
	if (c + 3 >= mi && cnt < 9) return;
	if (c + 4 >= mi && cnt < 6) return;
	for (int ty = 0; ty < 2; ty++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				shift(ty, i);
				tmp[c][0] = ty+1, tmp[c][1] = i + 1, tmp[c][2] = j + 1;
				func(c + 1);
			}
			shift(ty, i);
		}
	}
}
int main() {
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) scanf("%d", &rect[i][j]);
	func(0);
	printf("%d\n", mi);
	for (int i = 0; i < mi; i++) printf("%d %d %d\n", ret[i][0], ret[i][1], ret[i][2]);
	return 0;
}
