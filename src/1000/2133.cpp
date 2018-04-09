#include<iostream>
using namespace std;
typedef long long ll;
int N;
ll dp[31];
int main()
{
	cin >> N;
	if(N&1)
		cout << "0\n";
	else
	{
		dp[0] = 1;
		dp[2] = 3;
		for (int i = 4; i <= N; i += 2)
		{
			dp[i] = dp[i - 2] * 3;
			for (int j = 4; j <= i; j += 2)
				dp[i] += dp[i - j] * 2;
		}
		cout << dp[N] << "\n";
	}
	return 0;
}