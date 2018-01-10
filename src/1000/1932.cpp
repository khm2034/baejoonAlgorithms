#include<iostream>

using namespace std;

void input();
void solution();
int max(int a, int b);

int triSize;
int tri[502][502] = { 0, };
int dp[502][502] = { 0, };
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
	cin >> triSize;

	for (int i = 1; i <= triSize; i++)
	{
		for (int j = 1; j <= i; j++)
			cin >> tri[i][j];
	}
}

void solution()
{
	dp[1][1] = tri[1][1];

	for (int i = 2; i <= triSize; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = tri[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}

	for (int i = 1; i <= triSize; i++)
	{
		if (result < dp[triSize][i])
			result = dp[triSize][i];
	}
}

int max(int a, int b)
{
	return a > b ? a : b;
}