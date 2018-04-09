#include<iostream>
#include<memory.h>
#define QUEUESIZE 2505
using namespace std;

int W, H;
int map[51][51];
bool visit[51][51];
pair<int, int> q[2505];
int front, rear;
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
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
	return x >= 0 && x < W && y >= 0 && y < H;
}

void bfs(int x, int y)
{
	push(x, y);
	visit[y][x] = true;
	while (rear != front)
	{
		pair<int, int> t = pop();
		int tx, ty;
		for (int i = 0; i < 8; i++)
		{
			tx = t.first + dx[i];
			ty = t.second + dy[i];
			if (safe(tx, ty) && map[ty][tx] && !visit[ty][tx])
			{
				visit[ty][tx] = true;
				push(tx, ty);
			}
		}
	}
}

int main()
{
	while (1)
	{
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		cin >> W >> H;
		if (!W && !H)
			break;
		for (int i = 0; i<H; i++)
			for (int j = 0; j < W; j++)
				cin >> map[i][j];

		int cnt = 0;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				if (map[i][j] && !visit[i][j])
				{
					bfs(j, i);
					cnt++;
				}
		cout << cnt << "\n";
	}
	return 0;
}