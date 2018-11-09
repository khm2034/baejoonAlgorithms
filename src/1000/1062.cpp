#include<cstdio>
#define max(a,b) a>b?a:b
int N, K, ret;
char s[51][16];
bool visit[26];
void func(int idx, int cnt) {
	if (!cnt) {
		int c = 0;
		for (int i = 0; i < N; i++) {
			bool flag = true;
			for (int j = 0; s[i][j]; j++) {
				if (!visit[s[i][j] - 'a']) {
					flag = false;
					break;
				}
			}
			if (flag) c++;
		}
		ret = max(ret, c);
	}
	for (int i = idx; i < 26; i++)
		if (!visit[i]) {
			visit[i] = true;
			func(i + 1, cnt - 1);
			visit[i] = false;
		}
}
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%s", s[i]);
	if (K < 5) printf("0\n");
	else {
		visit[0] = visit['n' - 'a'] = visit['t' - 'a'] = visit['c' - 'a'] = visit['i' - 'a'] = true;
		func(1, K - 5);
		printf("%d", ret);
	}
	return 0;
}