#include<iostream>
#include<cstdio>
#include<algorithm>
#define QUEUESIZE 10005
using namespace std;

int map[101][101];
bool visit[101][101];
int M, N, K;

int dx[4] = { 1, 0 , -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

pair<int, int> q[QUEUESIZE];
int rear, front;

int arr[5001];
int arr_idx;
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

int bfs()
{
	int cnt = 0;
	while (front != rear)
	{
		cnt++;
		pair<int, int> t = pop();
		int tx, ty;
		for (int i = 0; i < 4; i++)
		{
			tx = t.first + dx[i];
			ty = t.second + dy[i];
			if (safe(tx, ty) && map[ty][tx] == 0 && !visit[ty][tx])
			{
				visit[ty][tx] = true;
				push(tx, ty);
			}
		}
	}
	return cnt;
}

int main()
{
	scanf("%d%d%d", &M, &N, &K);
	int x1, x2, y1, y2;
	for (int i = 0; i < K; i++)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

		for (int r = y1; r < y2; r++)
			for (int c = x1; c < x2; c++)
				map[r][c] = 1;
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 0 && !visit[i][j])
			{
				push(j, i);
				visit[i][j] = true;
				arr[arr_idx++] = bfs();
			}
		}
	}
	sort(arr, arr + arr_idx);
	printf("%d\n", arr_idx);
	for (int i = 0; i < arr_idx; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}