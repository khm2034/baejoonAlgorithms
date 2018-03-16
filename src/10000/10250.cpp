#include<iostream>
#include<cstdio>
using namespace std;

int T;
int H, W, N;
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		scanf("%d%d%d", &H, &W, &N);
		if((N%H)==0)
			printf("%d\n", H * 100 + N / H );
		else
			printf("%d\n", (N%H) * 100 + N / H + 1);
	}
	return 0;
}