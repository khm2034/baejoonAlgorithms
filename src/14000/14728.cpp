#include <iostream>
#include <algorithm>
using namespace std;

int N, T;
pair<int, int> info[101];
int dp[101][10001] = { 0, };

void inputData()
{
	cin >> N >> T;
	for (int i = 0; i < N; i++)
		cin >> info[i].first >> info[i].second;
}

int solve(int num, int s)
{
	if (num >= N)
		return 0;
	int& ret = dp[num][s];
	if (ret != 0)
		return ret;

	if (s + info[num].first <= T)
		ret = max(ret, solve(num + 1, s + info[num].first)+info[num].second);

	ret = max(ret, solve(num + 1, s));

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