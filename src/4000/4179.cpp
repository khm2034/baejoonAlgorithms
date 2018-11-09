#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
using namespace std;

int map[1001][1001], visit_f[1001][1001], visit_j[1001][1001];
int R, C;
queue<pair<int,int>> q_j, q_f;
char c;
int dx[4] = { 1, 0, -1, 0 } , dy[4] = { 0, 1, 0, -1 };
bool safe(int x, int y)
{
	return x >= 0 && x < C && y >= 0 && y < R;
}
void bfs_f()
{
	while (!q_f.empty())
	{
		pair<int, int> t = q_f.front(); q_f.pop();
		for (int i = 0, tx, ty; i < 4; i++)
		{
			tx = t.first + dx[i]; ty = t.second + dy[i];
			if (safe(tx, ty) && !visit_f[ty][tx] && !map[ty][tx])
			{
				visit_f[ty][tx] = visit_f[t.second][t.first] + 1;
				q_f.push(make_pair(tx, ty));
			}
		}
	}
}
int bfs_j()
{
	while (!q_j.empty())
	{
		pair<int, int> t = q_j.front(); q_j.pop();
		for (int i = 0, tx, ty; i < 4; i++)
		{
			tx = t.first + dx[i]; ty = t.second + dy[i];
			if (safe(tx, ty) && !visit_j[ty][tx] && !map[ty][tx]
				&& (visit_f[ty][tx] > visit_j[t.second][t.first]+1 || visit_f[ty][tx] == 0))
			{
				visit_j[ty][tx] = visit_j[t.second][t.first] + 1;
				q_j.push(make_pair(tx, ty));
			}
			else if(!safe(tx, ty))
				return visit_j[t.second][t.first];
		}
	}
	return -1;
}
int main()
{
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf(" %c", &c);
			if (c == '#')
				map[i][j] = -1;
			else if (c == 'J')
			{
				q_j.push(make_pair(j, i));
				visit_j[i][j] = 1;
			}
			else if (c == 'F')
			{
				q_f.push(make_pair(j, i));
				visit_f[i][j] = 1;
			}
		}
	}
	bfs_f();
	int ret = bfs_j();
	ret < 0 ? printf("IMPOSSIBLE\n") : printf("%d\n", ret);
	return 0;
}