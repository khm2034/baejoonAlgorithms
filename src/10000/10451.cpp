#include <iostream>


using namespace std;

void input();
void solution();
void dfs(int n);

int permuSize;
int permu[1002] = { 0, };
int visit[1002] = { 0, };
int result = 0;

int main()
{
	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		input();
		solution();
		cout << result << endl;

		result = 0;
		for (int i = 1; i <= permuSize; i++)
		{
			permu[i] = 0;
			visit[i] = 0;
		}
	}

	return 0;
}

void input()
{
	cin >> permuSize;

	for (int i = 1; i <= permuSize; i++)
	{
		cin >> permu[i];
	}
}

void solution()
{
	for (int i = 1; i <= permuSize; i++)
	{
		if (visit[i] != 0)
			continue;
		dfs(i);
		result++;
	}
}

void dfs(int n)
{
	if (visit[n] != 0)
		return;

	visit[n] = 1;
	dfs(permu[n]);

	return;
}