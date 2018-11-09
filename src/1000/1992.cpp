#include<cstdio>
int N,idx;
char s[20000], map[65][65];
bool chk(int n, int x, int y)
{
	char t = map[y][x];
	for (int i = y; i < y+n; i++)
		for (int j = x; j < x+n; j++)
			if (map[i][j] != t)
				return false;
	return true;
}
void func(int n, int x, int y)
{
	if (!chk(n, x, y))
	{
		s[idx++] = '(';
		func(n / 2, x, y);
		func(n / 2, x + (n / 2), y);
		func(n / 2, x, y + (n / 2));
		func(n / 2, x + (n / 2), y + (n / 2));
		s[idx++] = ')';
	}
	else
		s[idx++] = map[y][x];
}
int main()
{
	scanf("%d", &N);
	char t;
	for(int i=0; i<N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf(" %c", &t);
			map[i][j] = t;
		}
	func(N, 0, 0);
	printf("%s\n", s);
	return 0;
}