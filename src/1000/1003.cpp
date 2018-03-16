#include <cstdio>
using namespace std;

int dp[41][2] = { 0, };

int fibo(int n, int x)
{
	if (n == 0 || n == 1)
		if (n == x)
			return dp[n][x] = 1;
		else
			return 0;
	int& ret = dp[n][x];

	if (ret != 0)
		return ret;

	return ret = fibo(n - 1, x) + fibo(n - 2, x);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		int n, result[2];
		scanf("%d", &n);
		result[0] = fibo(n, 0);
		result[1] = fibo(n, 1);
		printf("%d %d\n", result[0], result[1]);
	}
	return 0;
}