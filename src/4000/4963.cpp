#include<iostream>
#define QUEUESIZE (52*2+5)
using namespace std;


int map[52][52];
int visit[52][52];
int w;
int h;

int dx[8] = { 1, 1, 0 ,-1, -1, -1, 0, 1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int cnt = 0;

void init()
{
	cnt = 0;
	for (int i = 0; i <= h + 1; i++)
		for (int j = 0; j <= w + 1; j++)
			map[i][j] = visit[i][j] = 0;
}

void inputData()
{
	init();
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> map[i][j];
}

struct point {
	int x;
	int y;
};

point queue[QUEUESIZE];
int front = 0;
int rear = 0;

void push(int x, int y)
{
	rear++;
	rear = rear % QUEUESIZE;
	queue[rear].x = x;
	queue[rear].y = y;
}

point pop()
{
	front++;
	front = front % QUEUESIZE;
	return queue[front];
}


void bfs(int x, int y)
{
	cnt++;
	push(x, y);
	visit[y][x] = 1;

	while (rear != front)
	{
		point t = pop();

		for (int i = 0; i < 8; i++)
		{
			int tmpX = t.x + dx[i];
			int tmpY = t.y + dy[i];

			if (map[tmpY][tmpX] == 1 && visit[tmpY][tmpX] == 0)
			{
				push(tmpX, tmpY);
				visit[tmpY][tmpX] = 1;
			}
		}
	}
}

void solution()
{
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			if (map[i][j] == 1 && visit[i][j] == 0)
				bfs(j, i);
}

int main()
{
	freopen("input.txt", "r", stdin);
	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		inputData();
		solution();
		cout << cnt << "\n";
	}
	
	return 0;
}