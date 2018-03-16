#include <iostream>
#include <algorithm>
using namespace std;

int arr[50001];
int dp[3][50001];
int sumDp[50001];
int N, maxN;
void inputData()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> maxN;
}

int getSum(int n)
{
	if (sumDp[n] != 0)
		return sumDp[n];
	int ret = 0;
	for (int i = 0; i < maxN; i++)
	{
		if (i + n == 50000)
			break;
		ret += arr[i + n];
	}
	return sumDp[n] = ret;
}

int solve(int small, int n)
{
	if (small == 3)
		return 0;
	if (n >= N)
		return 0;
	int& ret = dp[small][n];

	if (ret != 0)
		return ret;

	ret = max(solve(small, n + 1), solve(small + 1, n + maxN) + getSum(n));

	return ret;
}

int main()
{
	freopen("input.txt", "r", stdin);
	inputData();
	int result = solve(0, 0);
	cout << result << "\n";
	
	return 0;
}