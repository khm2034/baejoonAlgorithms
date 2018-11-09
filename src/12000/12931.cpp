#include<cstdio>
int B[51], N, cnt;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &B[i]);
	while (1){
		int z = 0;
		bool f = 0;
		for (int i = 0; i < N; i++) {
			if (B[i] & 1) {
				B[i]--;
				cnt++;
				f = 1;
			}
			if (!B[i]) z++;
		}
		if (z == N)break;
		if (!f) {
			cnt++;
			for (int i = 0; i < N; i++) B[i] >>= 1;
		}
	}
	printf("%d", cnt);
	return 0;
}