#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;
int dp[4005][4005];
int ret = 0;
void solution()
{
	int a_l = a.length();
	int b_l = b.length();
	if (a_l > b_l)
	{
		swap(a, b);
		swap(a_l, b_l);
	}

	for (int i = 1; i < b_l + 1; i++)
	{
		for (int j = 1; j < a_l + 1; j++)
		{
			if (a[j - 1] == b[i - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (ret < dp[i][j])
					ret = dp[i][j];
			}
			else
				dp[i][j] = 0;
		}
	}
	cout << ret << "\n";
}

int main()
{
	cin >> a >> b;
	solution();
	return 0;
}