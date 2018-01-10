#include <iostream>
#include <vector>

using namespace std;

struct C 
{
	int n;
	int r;
};

void input();
int solution(int n, int r);

int T;
vector<C*> inputData;
vector<int> result;
int dp[32][32] = { 0, };

int main()
{
	input();

	for (int i = 0; i < T; i++)
	{
		result.push_back(solution(inputData[i]->n, inputData[i]->r));
	}

	for (int i = 0; i < T; i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}

void input()
{
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		C* temp = new C();

		cin >> temp->r >> temp->n;
		inputData.push_back(temp);
	}
}

int solution(int n, int r)
{
	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				dp[i][j] = 1;
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			}

			if (i == n && j == r)
				return dp[n][r];
		}
	}

	return dp[n][r];
}