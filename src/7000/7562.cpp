#include<iostream>
#include<cstdio>
#include<memory.h>
#define QUEUESIZE (300*300+5)
using namespace std;

int T, N;
int sx, sy, ex, ey;
int visit[301][301];
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
pair<int, int> q[QUEUESIZE];
int front, rear;
void push(int x, int y)
{
	rear++;
	rear = rear % QUEUESIZE;
	q[rear].first = x;
	q[rear].second = y;
}
pair<int, int> pop()
{
	front++;
	front = front % QUEUESIZE;
	return q[front];
}

bool safe(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}

int bfs()
{
	front = rear = 0;
	push(sx, sy);
	visit[sy][sx] = 1;
	while (front != rear)
	{
		pair<int, int> t = pop();
		int tx, ty;
		for (int i = 0; i < 8; i++)
		{
			tx = t.first + dx[i];
			ty = t.second + dy[i];
			if (safe(tx, ty) && !visit[ty][tx])
			{
				visit[ty][tx] = visit[t.second][t.first] + 1;
				if (ty == ey && tx == ex)
					return visit[ty][tx] - 1;
				push(tx, ty);
			}
		}
	}
	return 0;
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		memset(visit, 0, sizeof(visit));
		scanf("%d", &N);
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		printf("%d\n",bfs());
	}
	return 0;
}