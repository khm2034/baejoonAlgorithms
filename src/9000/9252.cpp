#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;
int a_l;
int b_l;
int dp[1002][1002];
string ret;

void input_data()
{
	cin >> a >> b;
	a_l = a.length();
	b_l = b.length();
}

void solution()
{
	if (a_l > b_l)
	{
		swap(a, b);
		swap(a_l, b_l);
	}

	for (int i = 1; i <= b_l; i++)
	{
		for (int j = 1; j <= a_l; j++)
		{
			if (b[i - 1] == a[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] +1;
			}
			else
			{
				if (dp[i][j - 1] >= dp[i - 1][j])
					dp[i][j] = dp[i][j - 1];
				else
					dp[i][j] = dp[i-1][j];
			}
		}
	}

	int i = b_l;
	int	j = a_l;
	while (1)
	{
		if (i < 1 || j < 1)
			break;

		if (dp[i - 1][j] == dp[i][j])
			i--;
		else if (dp[i][j - 1] == dp[i][j])
			j--;
		else
		{
			ret.push_back(a[--j]);
			i--;
		}
	}
	printf("%d\n", dp[b_l][a_l]);
	for (int i = dp[b_l][a_l] - 1; i >= 0; i--)
	{
		printf("%c", ret[i]);
	}
	printf("\n");
}

int main()
{
	freopen("input.txt", "r", stdin);
	input_data();
	solution();
	return 0;
}