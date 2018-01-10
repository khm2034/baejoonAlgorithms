#include<iostream>
#include<algorithm>

using namespace std;

int n;
int k;
int coin[101] = { 0, };
int dp[10001] = { 0, };

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}

	sort(coin, coin + n);

}

void solution()
{
	dp[0] = 1;
	for (int i = 0; i < n ;i++)
	{
		for (int j = 0; j <= k; j++)
			if(j - coin[i] >= 0)
				dp[j] += dp[j-coin[i]];
	}
}

//void solution()
//{
//	dp[0] = 1;
//	for (int i = 1; i <= k; i++)
//	{
//		for (int j = 0; j < n; j++)
//			if (i - coin[j] >= 0)
//				dp[i] += dp[i - coin[j]];
//	}
//}

int main()
{
	input();
	solution();
	
	cout << dp[k] << endl;
	return 0;
}