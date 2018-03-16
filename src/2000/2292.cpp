#include <iostream>
using namespace std;
typedef long long ll;

ll dp[1000000];
int main()
{
	ll N;
	int i;
	cin >> N;
	if (N == 1)
		cout << "1\n";
	else
	{
		dp[1] = 1;
		for (i = 2; i < 1000000; i++)
		{
			dp[i] = dp[i - 1] + (6 * (i - 1));
			if (dp[i] >= N)
				break;
		}
		cout << i << "\n";
	}
	return 0; 
}