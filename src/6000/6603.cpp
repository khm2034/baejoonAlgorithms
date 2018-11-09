#include<cstdio>
#include<memory.h>
using namespace std;

int K, S[14], ret[6];
void func(int d, int idx)
{
	if (K - idx + d < 6)
		return;
	if (d == 6)
	{
		for (int i = 0; i < 6; i++)
			printf("%d ", ret[i]);
		printf("\n");
		return;
	}

	for (int i = idx; i < K; i++)
	{
		ret[d] = S[i];
		func(d + 1, i + 1);
		ret[d] = 0;
	}
}
int main()
{
	while (1)
	{
		scanf("%d", &K);
		if (K == 0)
			break;
		memset(S, 0, sizeof(S));
		for (int i = 0; i < K; i++)
			scanf("%d", &S[i]);
		func(0, 0);
		printf("\n");
	}
	return 0;
}