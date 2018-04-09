#include<iostream>
#include<cstdio>
#include<memory.h>
#define QUEUESIZE (1000*1000*5)
using namespace std;

int N, M;
int map[1001][1001];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
pair<int, int> q[QUEUESIZE];

int rear = 0;
int front = 0;
int ret = 0;
void push(int x, int y)
{
	rear++;
	rear = rear%QUEUESIZE;
	q[rear].first = x;
	q[rear].second = y;
}
pair<int, int> pop()
{
	front++;
	front = front%QUEUESIZE;
	return q[front];
}

bool safe(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

void bfs()
{
	while (rear != front)
	{
		pair<int, int> t = pop();
		for (int i = 0; i < 4; i++)
		{
			int tmp_x = t.first + dx[i];
			int tmp_y = t.second + dy[i];
			if (safe(tmp_x, tmp_y) && map[tmp_y][tmp_x] == 0)
			{
				map[tmp_y][tmp_x] = map[t.second][t.first] + 1;
				push(tmp_x, tmp_y);
				if (ret < map[tmp_y][tmp_x]-1)
					ret = map[tmp_y][tmp_x]-1;
			}
		}
	}
}
int chk()
{
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (!map[i][j])
				return -1;
	return ret;
}
int main()
{
	scanf("%d%d", &N, &M);
	int tmp;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &tmp);
			if (tmp == 1)
				push(j, i);
			map[i][j] = tmp;
		}

	bfs();
	printf("%d\n", chk());
	return 0;
}