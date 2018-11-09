#include<iostream>
#include<cstdio>
#include<queue>
#include<memory.h>
using namespace std;

int N,M, map[51][51];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ret = 1e9;
bool safe(int x, int y, int tx, int ty)
{
	return tx >= x && tx < x + 8 && ty >= y && ty < y + 8;
}
void bfs(int x, int y, int c)
{
	int cnt = 0;
	queue<pair<int, int>> q;
	int visit[51][51] = { 0, };
	q.push({ x, y });
	visit[y][x] = c;
	if (map[y][x] != c)
		cnt++;
	while (!q.empty())
	{
		pair<int, int> t = q.front(); q.pop();
		for (int i = 0, tx, ty; i < 4; i++)
		{
			tx = t.first + dx[i]; ty = t.second + dy[i];
			if (safe(x, y, tx, ty) && !visit[ty][tx])
			{
				if (map[ty][tx] == visit[t.second][t.first])
				{
					cnt++;
					if (cnt > ret) return;
				}
				visit[ty][tx] = -visit[t.second][t.first];
				q.push({ tx, ty });
			}
		}
	}
	if (ret > cnt)
		ret = cnt;
}
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		char t;
		for (int j = 0; j < M; j++)
		{
			scanf(" %c", &t);
			if (t == 'B')
				map[i][j] = 1;
			else
				map[i][j] = -1;
		}
	}
	for(int i=0; i<=N-8; i++)
		for (int j = 0; j <= M - 8; j++)
		{
			bfs(j, i, map[i][j]);
			bfs(j, i, -map[i][j]);
		}
	printf("%d\n", ret);
	return 0;
}