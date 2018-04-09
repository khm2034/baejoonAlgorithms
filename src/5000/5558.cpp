#include<iostream>
#include<string>
#include<memory.h>
#define QUEUESIZE 1000005
using namespace std;

int H, W, N;
int map[1001][1001];
int visit[1001][1001];
pair<int, int > q[QUEUESIZE];
int front, rear;
int limit = 1;
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
	return x >= 0 && x < W && y >= 0 && y < H;
}
int bfs()
{
	while (front != rear)
	{
		pair<int, int> t = pop();
		int tx, ty;
		for (int i = 0; i < 4; i++)
		{
			tx = t.first + dx[i];
			ty = t.second + dy[i];
			if (safe(tx, ty) && !visit[ty][tx] && map[ty][tx] != -1)
			{
				visit[ty][tx] = visit[t.second][t.first] + 1;
				if (!map[ty][tx] || map[ty][tx] > limit)
					push(tx, ty);
				else if(map[ty][tx] == limit)
				{
					map[ty][tx] = 0;
					if (limit == N)
						return visit[ty][tx];
					int tmp = visit[ty][tx];
					limit++;
					memset(visit, false, sizeof(visit));
					visit[ty][tx] = tmp;
					front = rear = 0;
					push(tx, ty);
					break;
				}

			}
		}
	}
}
int main()
{
	cin >> H >> W >> N;
	string s;
	for (int i = 0; i < H; i++)
	{
		cin >> s;
		for (int j = 0; s[j]; j++)
		{
			if (s[j] == 'S')
				push(j, i);
			else if (s[j] == '.')
				map[i][j] = 0;
			else if (s[j] == 'X')
				map[i][j] = -1;
			else
				map[i][j] = s[j] - '0';
		}
	}
	cout << bfs() << "\n";
	return 0;
}