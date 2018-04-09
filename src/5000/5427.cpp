#include<iostream>
#include<string>
#include<memory.h>
#define QUEUESIZE 1000005
using namespace std;

struct qu
{
	pair<int, int> q[QUEUESIZE];
	int front, rear;
	qu() { front = rear = 0; }
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
};

int T, W, H;
int visit_f[1001][1001];
int visit_s[1001][1001];
int map[1001][1001];
string s;
qu q_f, q_s;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool safe(int x, int y)
{
	return x >= 0 && x < W && y >= 0 && y < H;
}

void bfs_f()
{
	while (q_f.front != q_f.rear)
	{
		pair<int, int> t = q_f.pop();
		int tx, ty;
		for (int i = 0; i < 4; i++)
		{
			tx = t.first + dx[i];
			ty = t.second + dy[i];
			if (safe(tx, ty) && !map[ty][tx] && !visit_f[ty][tx])
			{
				visit_f[ty][tx] = visit_f[t.second][t.first] + 1;
				q_f.push(tx, ty);
			}
		}
	}
}

int bfs_s()
{
	while (q_s.front != q_s.rear)
	{
		pair<int, int> t = q_s.pop();
		int tx, ty;
		for (int i = 0; i < 4; i++)
		{
			tx = t.first + dx[i];
			ty = t.second + dy[i];
			if (safe(tx, ty)) 
			{
				if (!map[ty][tx]&& !visit_s[ty][tx]
					&& (visit_f[ty][tx] > visit_s[t.second][t.first] + 1 || !visit_f[ty][tx]))
				{
					visit_s[ty][tx] = visit_s[t.second][t.first] + 1;
					q_s.push(tx, ty);
				}
			}
			else
			{
				q_s.front = q_s.rear = 0;
				return visit_s[t.second][t.first];
			}
		}
	}
	return 0;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		memset(visit_s, 0, sizeof(visit_s));
		memset(visit_f, 0, sizeof(visit_f));
		memset(map, 0, sizeof(map));
		cin >> W >> H;
		for (int i = 0; i < H; i++)
		{
			cin >> s;
			for (int j = 0; s[j]; j++)
			{
				if (s[j] == '#')
					map[i][j] = -1;
				else if (s[j] == '@')
				{
					visit_s[i][j] = 1;
					q_s.push(j, i);
				}
				else if (s[j] == '*')
				{
					visit_f[i][j] = 1;
					q_f.push(j, i);
				}
			}
		}
		bfs_f();
		int ret = bfs_s();
		if (!ret)
			cout << "IMPOSSIBLE\n";
		else
			cout << ret << "\n";
	}
	return 0;
}
