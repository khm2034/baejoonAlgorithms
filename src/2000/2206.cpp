#include <iostream>
#define QUEUESIZE (1000*2+5)
using namespace std;

int N;
int M;
int map[1002][1002];
int visit[1002][1002][2];
char s[1001];
int cnt = 1;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct point {
	int x;
	int y;
	bool state;
};

point queue[QUEUESIZE];
int front = 0;
int rear = 0;

void push(point i)
{
	rear++;
	rear = rear%QUEUESIZE;
	queue[rear] = i;
}

void push(int x, int y, bool state)
{
	rear++;
	rear = rear%QUEUESIZE;
	queue[rear].x = x;
	queue[rear].y = y;
	queue[rear].state = state;
}

point pop()
{
	front++;
	front = front%QUEUESIZE;
	return queue[front];
}
void printVisit(int n)
{
	cout << endl;
	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= M + 1; j++)
		{
			cout << visit[i][j][n] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


void bfs()
{
	push(1,1, false);
	visit[1][1][0] = 1;

	while (rear != front)
	{
		point t = pop();
		for (int i = 0; i < 4; i++)
		{
			int tmpX;
			int tmpY;
			tmpX = t.x + dx[i];
			tmpY = t.y + dy[i];

			if (map[tmpY][tmpX] == -1)
				continue;

			if (map[tmpY][tmpX] == 1)
			{
				if (t.state)
					continue;

				push(tmpX, tmpY, true);
				visit[tmpY][tmpX][1] = visit[t.y][t.x][0] + 1;
			}
			else 
			{
				// º® ¶Õ
				if (t.state)
				{
					if (visit[tmpY][tmpX][1] == 0)
					{
						push(tmpX, tmpY, true);
						visit[tmpY][tmpX][1] = visit[t.y][t.x][1] + 1;
					}
				}
				else //º® ¾È¶Õ
				{
					if (visit[tmpY][tmpX][0] == 0)
					{
						push(tmpX, tmpY, false);
						visit[tmpY][tmpX][0] = visit[t.y][t.x][0] + 1;
					}
				}
			}

			if (tmpX == M && tmpY == N)
				return;
		}
		printVisit(0);
		//printVisit(1);
		//pair<int, int> t(q.pop();
	}
}

void init()
{
	for (int i = 0; i <= N+1; i++)
		for (int j = 0; j <= M+1; j++)
		{
			map[i][j] = -1;
			visit[i][j][0] = 0;
			visit[i][j][1] = 0;
		}
}

void printMap()
{
	for (int i = 0; i <= N+1; i++)
	{
		for (int j = 0; j <= M+1; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}


void inputData()
{
	cin >> N >> M;
	init();
	for (int i = 1; i <= N; i++)
	{
		cin >> s;
		for (int j = 1; j <= M; j++)
		{
			map[i][j] = s[j - 1] - '0';
		}
	}
	printMap();
}



int min(int a, int b)
{
	return (a > b) ? b : a;
}

int main()
{
	freopen("input.txt", "r", stdin);
	inputData();
	bfs();

//	printVisit(0);
//	printVisit(1);

	if (visit[N][M][0] == 0 && visit[N][M][1] == 0)
		cout << "-1\n";
	else if (visit[N][M][0] == 0)
		cout << visit[N][M][1] << "\n";
	else if(visit[N][M][1] == 0)
		cout << visit[N][M][0] << "\n";
	else
		cout << min(visit[N][M][0], visit[N][M][1]) << "\n";
	return 0;
}
