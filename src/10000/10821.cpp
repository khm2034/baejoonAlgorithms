#include<cstdio>
char s[105];
int cnt;
int main()
{
	scanf("%s", s);
	for (int i = 0; s[i]; i++)
		if (s[i] == ',')
			cnt++;
	printf("%d\n", cnt+1);
	return 0;
}