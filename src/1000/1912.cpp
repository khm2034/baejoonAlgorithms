#include <iostream>

using namespace std;

void input();
void solution();

int inputData[100001] = { 0, };
int n;
int cmax = 0;
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
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> inputData[i];
}

void solution()
{
	for (int i = 0; i < n; i++) 
	{
		cmax += inputData[i];

		if (cmax < 0)
			cmax = 0;

		if (result < cmax)
			result = cmax;

	}

	if (result == 0)
	{
		result = inputData[0];

		for (int i = 1; i < n; i++)
			if (result < inputData[i])
				result = inputData[i];
	}
}