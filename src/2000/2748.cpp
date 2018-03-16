#include <iostream>
using namespace std;
typedef long long ll;
ll dp[91];

ll fibo(int n)
{
	if (n == 0 || n == 1)
		return dp[n] = n;

	ll& ret = dp[n];
	if (ret != 0)
		return ret;

	return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
	int n;
	cin >> n;
	cout << fibo(n) << "\n";
	return 0;
}