#include <iostream>
#include <memory.h>
#define QUEUESIZE 90005
using namespace std;

int N;
int M;
int map[301][301] = { 0, };
bool visit[301][301];
pair<int, int> q[QUEUESIZE];
int front, rear;
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
	visit[y][x] = true;
	push(x, y);
	while (rear != front)
	{
		pair<int, int> t = pop();
		int tx, ty;
		for (int i = 0; i < 4; i++)
		{
			tx = t.first + dx[i];
			ty = t.second + dy[i];
			if (safe(tx, ty))
			{
				if (!map[ty][tx] && map[t.second][t.first] && !visit[ty][tx])
					map[t.second][t.first]--;
				else if(map[ty][tx] && !visit[ty][tx])
				{
					visit[ty][tx] = true;
					push(tx, ty);
				}
			}
		}
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	int ret = 0;
	while (1)
	{
		int cnt = 0;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] && !visit[i][j])
				{
					bfs(j, i);
					cnt++;
				}

		if (cnt > 1)
			break;
		else if (!cnt)
		{
			ret = 0;
			break;
		}

		ret++;
	}
	cout << ret << "\n";
	return 0;
}