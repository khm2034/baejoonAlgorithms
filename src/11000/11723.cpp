#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int S = 0;
int allV = (1 << 20) - 1;
int main()
{
	freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	char oper[10];
	int num;
	for (int n = 0; n < N; ++n)
	{
		scanf("%s", oper);
		if (oper[0] == 'a')
		{
			if (oper[1] == 'l')
				S = allV;
			else
			{
				scanf("%d", &num);
				S = S | 1 << (num - 1);
			}
		}
		else if (oper[0] == 'r')
		{
			scanf("%d", &num);
			S = S & ~(1 << (num - 1));
		}
		else if (oper[0] == 'c')
		{
			scanf("%d", &num);
			if (S & (1 << (num - 1)))
				printf("1\n");
			else
				printf("0\n");
		}
		else if (oper[0] == 't')
		{
			scanf("%d", &num);
			S = S ^ (1 << (num - 1));
		}
		else if (oper[0] == 'e')
		{
			S = 0;
		}
	}
	return 0;
}