#include<cstdio>
int L, P, V;
int main() {
	for(int i=1;;i++) {
		int ret = 0;
		scanf("%d%d%d", &L, &P, &V);
		if (!L && !P && !V) break;
		ret += (V / P)*L;
		V %= P;
		ret += (V > L ? L : V);
		printf("Case %d: %d\n", i, ret);
	}
	return 0;
}