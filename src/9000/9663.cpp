#include<iostream>
#include<cstdio>
using namespace std;

int N;
int ret;
void func(int n, int left, int mid, int right)
{
	if (n == N)
	{
		ret++;
		return;
	}

	int n_left = 0;
	int n_mid = 0;
	int n_right = 0;
	for (int i = 1; i < 1 << N; i = i << 1)
	{
		if (left & i)
			n_left |= i << 1;
		if (mid & i)
			n_mid |= i;
		if (right&i)
			n_right |= i >> 1;
	}
	for (int i = 1; i < 1 << N; i = i << 1)
	{
		if (!(n_left &i) && !(n_right&i) && !(n_mid&i))
		{
			n_left |= i;
			n_right |= i;
			n_mid |= i;
			func(n + 1, n_left, n_mid, n_right);
			n_left &= ~i;
			n_right &= ~i;
			n_mid &= ~i;
		}
	}
}
int main()
{
	int left = 0;
	int mid = 0;
	int right = 0;
	scanf("%d", &N);
	func(0, left, mid, right);
	printf("%d\n", ret);
	return 0;
}