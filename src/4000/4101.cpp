#include<cstdio>

int a, b;
int main()
{
	while (1)
	{
		scanf("%d%d", &a,&b);
		if (!a && !b) break;
		printf("%s\n", a > b ? "Yes" : "No");
	}
	return 0;
}