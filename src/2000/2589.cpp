#include <iostream>
#include <cstdio>
#define QUEUESIZE 2505
using namespace std;

int Y, X;
char s[51];
int map[51][51];
int visit[51][51][2501];
int visit_idx;
pair<int, int> q[QUEUESIZE];
int front, rear;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ret;
void push(int x, int y)
{
	rear++;
	rear = rear % QUEUESIZE;
	q[rear].first = x;
	q[rear].second = y;
}

pair<int, int>pop()
{
	front++;
	front = front % QUEUESIZE;
	return q[front];
}

bool safe(int x, int y)
{
	return x >= 0 && x < X && y >= 0 && y < Y;
}

void bfs(int x, int y)
{
	int tmp_ret = 0;
	push(x, y);
	visit[y][x][visit_idx] = 1;
	while (rear != front)
	{
		pair<int, int> t = pop();
		int tx, ty;
		for (int i = 0; i < 4; i++)
		{
			tx = t.first + dx[i];
			ty = t.second + dy[i];
			if (safe(tx, ty) && !map[ty][tx] && !visit[ty][tx][visit_idx])
			{
				visit[ty][tx][visit_idx] = visit[t.second][t.first][visit_idx] + 1;
				if (tmp_ret < visit[ty][tx][visit_idx])
					tmp_ret = visit[ty][tx][visit_idx];
				push(tx, ty);
			}
		}
	}
	if (tmp_ret-1 > ret)
		ret = tmp_ret-1;
	visit_idx++;
}

int main()
{
	scanf("%d%d", &Y, &X);
	for (int i = 0; i < Y; i++)
	{
		scanf("%s", s);
		for (int j = 0; j < X; j++)
			if (s[j] == 'W')
				map[i][j] = 1;
			else
				map[i][j] = 0;
	}

	for (int i = 0; i < Y; i++)
		for (int j = 0; j < X; j++)
			if (!map[i][j])
				bfs(j, i);

	printf("%d\n", ret);
	return 0;
}