#include <iostream>
using namespace std;

int dp[46];

int fibo(int n)
{
	if (n == 0 || n == 1)
		return dp[n] = n;

	int& ret = dp[n];
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