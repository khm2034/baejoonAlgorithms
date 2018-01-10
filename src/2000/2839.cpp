#include <iostream>

using namespace std;

void input();
int solution();
int min(int x, int y);

int inputData;
int outputData = 0;
int dp[5001] = { 0, };

int main()
{
	input();
	cout << solution() << endl;
	return 0;
}

void input()
{
	cin >> inputData;
}

int solution()
{
	dp[0] = 0;
	dp[1] = -1;
	dp[2] = -1;
	dp[3] = 1;
	dp[4] = -1;
	dp[5] = 1;
	for (int i = 6; i <= inputData; i++)
	{
		if (dp[i - 3] >= 0 && dp[i - 5] >= 0)
		{
			dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
		}
		else if (dp[i - 3] >= 0)
			dp[i] = dp[i - 3] + 1;
		else if (dp[i - 5] >= 0)
			dp[i] = dp[i - 5] + 1;
		else
			dp[i] = -1;
	}

	return dp[inputData];
}

int min(int x, int y)
{
	return x <= y ? x : y;
}