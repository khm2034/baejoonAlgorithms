#include <iostream>
#include <cstdio>
using namespace std;

bool prime[1001];
int N, K;
int cnt = 0;
int ret;
int main()
{
	scanf("%d%d", &N, &K);

	for (int i = 2; i <= N; i++)
	{
		for(int j = i; j <= N; j += i)
		{
			if (!prime[j])
			{
				prime[j] = true;
				cnt++;
				if (cnt == K)
				{
					ret = j;
					goto label;
				}
			}
		}
	}
label:
	printf("%d\n", ret);
	return 0;
}