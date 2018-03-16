#include <iostream>
#define QUEUESIZE 2000*2000+5
using namespace std;

struct Point
{
	int id;
	int x;
	int y;
};

struct Visit
{
	int year;
	int id;
};

Visit visit[2002][2002];
int N, K;
Point q[QUEUESIZE];
int front = 0;
int rear = 0;

int parent[100001];
int r[100001];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void make_set(int x)
{
	parent[x] = x;
	r[x] = 0;
}

int find_set(int x)
{
	if (x != parent[x])
		parent[x] = find_set(parent[x]);

	return parent[x];
}

void union_set(int x, int y)
{
	x = find_set(x);
	y = find_set(y);
	if (r[x] > r[y])
		parent[y] = x;
	else
	{
		parent[x] = y;
		if (r[x] == r[y])
			r[y]++;
	}
}

void push(int id, int x, int y)
{
	rear++;
	rear %= QUEUESIZE;
	q[rear].id = id;
	q[rear].x = x;
	q[rear].y = y;
}

Point pop()
{
	front++;
	front %= QUEUESIZE;
	return q[front];
}

bool safePoint(int x, int y)
{
	return x >= 1 && x <= N && y >= 1 && y <= N;
}

void chk(int id, int x, int y)
{
	int tmp_x, tmp_y;
	for (int i = 0; i < 4; ++i)
	{
		tmp_x = x + dx[i];
		tmp_y = y + dy[i];
		if (safePoint(tmp_x, tmp_y) && visit[tmp_y][tmp_x].year >= 0)
		{
			if (visit[tmp_y][tmp_x].id != 0 && id != 0 &&
				find_set(visit[tmp_y][tmp_x].id) != find_set(id))
			{
				union_set(visit[tmp_y][tmp_x].id, id);
				K--;
			}
		}
	}
}

void inputData()
{
	cin >> N >> K;

	for(int i=0; i<2002; ++i)
		for (int j = 0; j < 2002; ++j)
		{
			visit[j][i].year = -1;
			visit[j][i].id = 0;
		}
	int x, y;
	int tmpK = K;
	for (int i = 0; i < tmpK; i++)
	{
		make_set(i + 1);
		cin >> x >> y;
		push(i+1, x, y);
		visit[y][x].year = 0;
		visit[y][x].id = i + 1;
		chk(i + 1, x, y);
	}
}

int solution()
{
	if (K == 1)
		return 0;
	while (rear != front)
	{
		Point t = pop();
		chk(t.id, t.x, t.y);
		if (K == 1)
			return visit[t.y][t.x].year;
		for (int i = 0; i < 4; ++i)
		{
			int tmpX = t.x + dx[i];
			int tmpY = t.y + dy[i];

			if (safePoint(tmpX, tmpY) && visit[tmpY][tmpX].year < 0)
			{
				chk(t.id, tmpX, tmpY);
				if (K == 1)
					return visit[t.y][t.x].year+1;
				push(find_set(t.id), tmpX, tmpY);
				visit[tmpY][tmpX].year = visit[t.y][t.x].year + 1;
				visit[tmpY][tmpX].id = find_set(visit[t.y][t.x].id);
			}
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	inputData();
	int ret = solution();
	cout << ret << "\n";
	return 0;
}
