#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

bool visit_a[30], visit_m[21][21];
int R, C, ret;
int map[21][21];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;
bool safe(int x, int y)
{
	return x >= 0 && x < C && y >= 0 && y < R;
}
void func(int x, int y, int m, int c)
{
	if (visit_m[y][x] || visit_a[m])
	{
		if (c > ret)
			ret = c;
		return;
	}
	visit_a[m] = true;
	visit_m[y][x] = true;
	for (int i = 0, tx, ty; i < 4; i++)
	{
		tx = x + dx[i]; ty = y + dy[i];
		if(safe(tx, ty))
			func(tx, ty, map[ty][tx], c + 1);
	}
	visit_a[m] = false;
	visit_m[y][x] = false;
}
int main()
{
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; i++)
	{
		char s[21];
		scanf("%s", s);
		for (int j = 0; s[j]; j++)
			map[i][j] = s[j] - 'A';
	}
	func(0, 0, map[0][0], 1);
	printf("%d\n", ret-1);
	return 0;
}