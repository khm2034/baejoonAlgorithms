#include <cstdio>

char s[1000001];
int main()
{
	scanf("%[^\n]s", s);
	int cnt = 0;
	int i;
	for (i = 0; s[i]; i++)
	{
		if (s[i] == ' ')
		{
			if (i == 0)
				continue;
			else
				cnt++;
		}
	}
	if (s[i - 1] != ' ')
		cnt++;
	printf("%d\n", cnt);
	return 0;
}