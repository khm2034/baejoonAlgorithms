#include<cstdio>
#define min(a,b) a>b?b:a
int N ,S, arr[100001], p_s[100002], ret = 1e6, le, ri, sum;
int main() {
	scanf("%d%d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] >= S) {
			printf("1\n");
			return 0;
		}
	}
	while (1){
		if (sum >= S) {
			ret = min(ret, ri - le);
			sum -= arr[le++];
		}
		else if (ri == N) break;
		else sum += arr[ri++];
	}
	printf("%d", ret == 1e6 ? 0 : ret);
	return 0;
}