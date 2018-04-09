#include<iostream>
#include<memory.h>
#define QUEUESIZE 2505
using namespace std;

int N, M, K;
int T;
int map[51][51];
bool visit[51][51];

pair<int, int> q[QUEUESIZE];
int rear, front;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
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
	return x >= 0 && x < M && y >= 0 && y < N;
}

void bfs(int x, int y)
{
	push(x, y);
	visit[y][x] = true;
	while (front != rear)
	{
		pair<int, int> t = pop();
		int tx, ty;
		for (int i = 0; i < 4; i++)
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
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		cin >> M >> N >> K;
		int x, y;
		int cnt = 0;
		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			map[y][x] = 1;
		}
		for (int i = 0; i<N; i++)
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] && !visit[i][j])
				{
					bfs(j, i);
					cnt++;
				}
			}

		cout << cnt << "\n";
	}
	return 0;
}