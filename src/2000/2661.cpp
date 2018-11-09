#include<cstdio>
using namespace std;

int arr[81];
int N;
bool chk(int n)
{
	for (int j = 1; j <= (n+1) / 2; j++)
	{

		bool ret = false;
		for (int k = 0; k < j; k++)
		{
			if (arr[n - j - j + k + 1] != arr[n - j + k + 1])
				ret = true;
		}
		if (!ret)
			return false;
	}
	return true;
}
bool func(int n)
{
	if (n == N)
	{
		for (int i = 0; i < N; i++)
			printf("%d", arr[i]);
		return true;
	}

	for (int i = 0; i < 3; i++)
	{
		arr[n] = i + 1;
		if (chk(n)) if (func(n + 1)) return true;
		arr[n] = 0;
	}
	return false;
}
int main()
{
	scanf("%d", &N);
	func(0);
	return 0;
}