#include<cstdio>
int N, M, arr[10001], p_s[10002], cnt;
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		p_s[i + 1] = p_s[i] + arr[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j <= N; j++) {
			if ((p_s[j] - p_s[i]) > M) break;
			if ((p_s[j] - p_s[i]) == M) cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}