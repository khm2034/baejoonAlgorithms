#include<cstdio>
using namespace std;

int N, min_v = 1e9, max_v = -1e9;
int main()
{
	scanf("%d", &N);
	for (int i = 0, x; i < N; i++)
	{
		scanf("%d", &x);
		if (x > max_v)
			max_v = x;
		if (x < min_v)
			min_v = x;
	}
	printf("%d %d\n", min_v, max_v);
	return 0;
}