#include <iostream>

using namespace std;

void input();
void solution();

int num;
int alcol[10001] = { 0, };
int dp[10001] = { 0, };
int result = 0;
int main()
{
	input();
	solution();

	cout << result << endl;
	return 0;
}

void input()
{
	cin >> num;

	for (int i = 1; i <= num; i++)
		cin >> alcol[i];
}

void solution()
{
	if(num == 1)
	{
		result = alcol[1];
		return;
	}

	dp[1] = alcol[1];
	dp[2] = alcol[1] + alcol[2];
	
	for (int i = 3; i <= num; i++)
	{
		dp[i] = dp[i - 1];
		if (dp[i] < dp[i - 2] + alcol[i])
			dp[i] = dp[i - 2] + alcol[i];

		if (dp[i] < dp[i - 3] + alcol[i - 1] + alcol[i])
			dp[i] = dp[i - 3] + alcol[i - 1] + alcol[i];
	}

	for (int i = 1; i <= num; i++)
	{
		if (result < dp[i])
			result = dp[i];
	}
}