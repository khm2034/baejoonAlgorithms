#include<cstdio>
#include<cstring>
#include<vector>
std::vector<int> v;
char P[1000001], T[1000001];
int pl, tl, f[1000001];
int main() {
	scanf("%[^\n]s", T); getchar();
	scanf("%[^\n]s", P);
	tl = strlen(T), pl = strlen(P);
	for (int i = 1, j = 0; i < pl; i++) {
		while (j > 0 && P[i] != P[j]) j = f[j - 1];
		if (P[i] == P[j]) f[i] = ++j;
	}
	for (int i = 0, j = 0; i < tl; i++) {
		while (j > 0 && T[i] != P[j]) j = f[j - 1];
		if (T[i] == P[j]) {
			if (j == pl - 1) {
				v.push_back(i - pl + 2);
				j = f[j];
			}
			else j++;
		}
	}
	printf("%d\n", v.size());
	for (int a : v) printf("%d\n", a);
	return 0;
}