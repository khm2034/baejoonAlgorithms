#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

bool prime[123456 * 2 + 1];
int N;
int main()
{
	for (int i = 2; i <= sqrt( 123456 * 2); i++)
	{
		if (prime[i])
			continue;
		for (int j = i+i; j <= 123456 * 2; j += i)
		{
			prime[j] = true;
		}
	}
	
	while (1)
	{
		int cnt = 0;
		scanf("%d", &N);
		if (N == 0)
			break;

		for (int i = N + 1; i <= N * 2; i++)
			if (!prime[i])
				cnt++;
		printf("%d\n", cnt);
	}

	return 0;
}