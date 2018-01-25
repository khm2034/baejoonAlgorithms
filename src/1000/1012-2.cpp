#include <iostream>
#define MAXSIZE 52
#define QUEUESIZE (MAXSIZE*2+1)
using namespace std;

int TC;
int M;
int N;
int K;
int map[MAXSIZE][MAXSIZE];
int visit[MAXSIZE][MAXSIZE];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int cnt = 0;

struct point {
	int x;
	int y;
};

point queue[QUEUESIZE];
int rear = 0;
int front = 0;

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
	front = front%QUEUESIZE;
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
		for (int i = 0; i < 4; i++)
		{
			int tmpX = t.x + dx[i];
			int tmpY = t.y + dy[i];

			if (map[tmpY][tmpX] != 0 && visit[tmpY][tmpX] == 0)
			{
				push(tmpX, tmpY);
				visit[tmpY][tmpX] = 1;
			}
		}
	}
}

void solution()
{
	for (int i = 1; i <= M; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (map[j][i] != 0 && visit[j][i] == 0)
				bfs(i, j);
		}
	}
}

void init()
{
	cnt = 0;
	for (int i = 0; i <= M + 1; i++)
		for (int j = 0; j <= N + 1; j++)
			map[j][i] = visit[j][i] = 0;
}

void inputData()
{
	cin >> M >> N;
	init();
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int tmpX, tmpY;
		cin >> tmpX >> tmpY;

		map[tmpY + 1][tmpX + 1] = 1;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> TC;
	for (int t = 0; t < TC; t++)
	{
		inputData();
		solution();
		cout << cnt << "\n";
	}
	return 0;
}