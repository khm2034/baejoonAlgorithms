#include <iostream>
#include <string>
using namespace std;

void input();
void solution(string s1, string s2);

string inputdata[2];
int stringL[2];

int dp[1001][1001] = { 0, };

int main()
{
	input();
	if (inputdata[0].length() >= inputdata[1].length())
		solution(inputdata[0], inputdata[1]);
	else
		solution(inputdata[1], inputdata[0]);

	return 0;
}

void input()
{
	for (int i = 0; i < 2; i++)
	{
		cin >> inputdata[i];
		cin.clear();
	}
}

void solution(string s1, string s2)
{
	for (int i = 1; i <= (int)s2.length(); i++)
	{
		for (int j = 1; j <= (int)s1.length(); j++)
		{
			if (s1[j - 1] == s2[i - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				if (dp[i - 1][j] >= dp[i][j - 1])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = dp[i][j-1];
			}
		}
	}

	cout << dp[s2.length()][s1.length()] << endl;
}