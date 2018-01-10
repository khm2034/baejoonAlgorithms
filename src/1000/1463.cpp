#include <iostream>

using namespace std;

void input();
void solution();

int num;
int dp[1000001] = { 0, };

int main()
{
	input();
	solution();

	cout << dp[num] << endl;
	return 0;
}

void input()
{
	cin >> num;
}

void solution()
{
	dp[1] = 0;

	for (int i = 2; i <= num; i++)
	{
		dp[i] = 1 + dp[i - 1];
		if (i % 3 == 0 && dp[i] > dp[i/3] +1)
		{
			dp[i] = dp[i / 3] + 1;
		}
		
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
		{
			dp[i] = dp[i / 2] + 1;
		}
	}
}