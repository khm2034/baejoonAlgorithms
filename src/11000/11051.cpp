#include <iostream>
using namespace std;
typedef long long ll;

ll N;
ll K;

ll dp[1001][1001];

ll cb(ll n, ll k)
{
	if (k == 0 || n == k)
		return dp[n][k] = 1;

	ll& ret = dp[n][k];
	if (ret != 0)
		return ret;
	return dp[n][k] = (cb(n - 1, k) % 10007 + cb(n - 1, k - 1) % 10007)%10007;
}

int main()
{
	cin >> N >> K;
	cb(N, K);
	cout << dp[N][K] << "\n";
	return 0;
}