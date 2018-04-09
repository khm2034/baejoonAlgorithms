#include <cstdio>
#include <iostream>
#define QUEUESIZE 1000005
using namespace std;

struct p {
	int x, y, z;
};
int M, N, H;
int map[101][101][101];
int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
p q[QUEUESIZE];
int front, rear;
void push(int x, int y, int z)
{
	rear++;
	rear = rear % QUEUESIZE;
	q[rear].x = x;
	q[rear].y = y;
	q[rear].z = z;
}
p pop()
{
	front++;
	front = front % QUEUESIZE;
	return q[front];
}

bool safe(int x, int y, int z)
{
	return x >= 0 && x < M && y >= 0 && y < N && z >= 0 && z < H;
}

void bfs()
{
	while (front != rear)
	{
		p t = pop();
		int tx, ty, tz;
		for (int i = 0; i < 6; i++)
		{
			tx = t.x + dx[i]; ty = t.y + dy[i]; tz = t.z + dz[i];
			if (safe(tx, ty, tz) && !map[tz][ty][tx])
			{
				map[tz][ty][tx] = map[t.z][t.y][t.x] + 1;
				push(tx, ty, tz);
			}
		}
	}
}

int main()
{
	scanf("%d%d%d", &M, &N, &H);
	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++)
			{
				scanf("%d", &map[i][j][k]);
				if (map[i][j][k] == 1)
					push(k, j, i);
			}
	bfs();
	int ret = 0;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++)
			{
				if (!map[i][j][k])
				{
					printf("-1\n");
					return 0;
				}
				if (ret < map[i][j][k])
					ret = map[i][j][k];
			}
	printf("%d\n", ret - 1);
	return 0;
}