#include<cstdio>
#include<cmath>
typedef long long ll;
ll N, dp[11][10] = { 0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1 };
ll ret = 9LL, tmp;
bool chk(ll& num, int k) {
	if (k == 0) return true;
	//ll a = ((num % (ll)pow(10, k + 1)) / (ll)pow(10, k));
	//ll b = ((num % (ll)pow(10, k)) / (ll)pow(10, k - 1)) % 10;
	if (((num % (ll)pow(10,k+1)) / (ll)pow(10, k))
			> ((num%(ll)pow(10,k)) /(ll)pow(10, k - 1)) % 10)
		return chk(num, k - 1);
	else {
		num = (num + (ll)pow(10, k)) - (num % (ll)pow(10, k));
		return false;
	}
	return false;
}
int main() {
	scanf("%lld", &N);
	if (N <= 9) {
		printf("%lld\n", N);
		return 0;
	}
	else {
		for (int i = 2; i <= 10; i++)
			for (int j = i-1; j < 10; j++)
				for (int k = 0; k <= j-1; k++) {
					dp[i][j] += dp[i - 1][k];
					ret += dp[i - 1][k];
					if (ret >= N) {
						ret -= dp[i - 1][k];
						tmp = j * pow(10, i - 1) + (k)*pow(10,i-2);
						while (1) {
							ll t = tmp;
							if (chk(tmp, i - 1)) {
								if (ret == N-1) break;
								ret++;
							}
							if(tmp == t)
								tmp++;
						}
						printf("%lld\n", tmp);
						return 0;
					}
				}
	}
	printf("-1\n");
	return 0; 
}

