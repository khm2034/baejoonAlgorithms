#include<cstdio>
int dp[301][301], N, M;
int func(int n, int m) {
	if (n == 1 && m == 1) return 0;
	int &ret = dp[n][m];
	if (ret) return ret;
	if (n > m) 
		if(n&1) return ret = func(n / 2 +1, m) + func(n / 2, m) + 1;
		else return ret = 2 * func(n / 2, m) + 1;
	else
		if (m & 1) return ret = func(n, m/2+1) + func(n, m/2) + 1;
		else return ret = 2 * func(n, m/2) + 1;
}
int main(){
	scanf("%d%d", &N, &M);
	printf("%d\n", func(N, M));
	return 0;
}