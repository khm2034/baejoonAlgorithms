#include<iostream>

using namespace std;

void input();
void solution();
int max(int a, int b);

int height;
int st[302] = { 0, };
int dp[302] = { 0, };
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
	cin >> height;

	for (int i = 1; i <= height; i++)
	{
		cin >> st[i];
	}
}

void solution()
{
	dp[1] = st[1];
	dp[2] = st[1] + st[2];
	
	for (int i = 3; i <= height; i++)
	{
		dp[i] = st[i] + max(dp[i - 2], dp[i - 3] + st[i - 1]);
	}

	result = dp[height];
}

int max(int a, int b)
{
	return a > b ? a : b;
}