#include <iostream>
#define S 1
#define D 2
#define X -1
#define WATER 3
#define QUEUESIZE 2505
#define INTMAX 99999999
using namespace std;

int map[52][52] = { 0, };
int visitW[52][52] = { 0, };
int visitG[52][52] = { 0, };
char s[51];
int R, C;
int sX, sY;
int eX, eY;
int result = 0;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct point {
	int x;
	int y;
};

point arr[QUEUESIZE];
int front = 0;
int rear = 0;

void push(int x, int y)
{
	rear++;
	rear = rear % QUEUESIZE;
	arr[rear].x = x;
	arr[rear].y = y;
}

point pop()
{
	front++;
	front = front % QUEUESIZE;
	return arr[front];
}

void init()
{
	for (int i = 0; i <= R + 1; i++)
		for (int j = 0; j <= C + 1; j++)
		{
			map[i][j] = -1;
			visitW[i][j] = INTMAX;
		}
}

void inputData()
{
	cin >> R >> C;
	init();
	for (int i = 1; i <= R; i++)
	{
		cin >> s;
		for (int j = 1; j <= C; j++)
		{
			switch (s[j-1]) {
			case 'D':
				eX = j;
				eY = i;
				map[i][j] = D;
				break;
			case 'S':
				map[i][j] = S;
				sX = j; 
				sY = i;
				break;
			case 'X':
				map[i][j] = X;
				break;
			case '*':
				map[i][j] = WATER;
				push(j, i);
				visitW[i][j] = 1;
				break;
			default:
				map[i][j] = 0;
				break;
			}
		}
	}

}

void bfsW()
{
	while (rear != front)
	{
		point t = pop();
		for (int i = 0; i < 4; i++)
		{
			int tmpX = t.x + dx[i];
			int tmpY = t.y + dy[i];

			if (map[tmpY][tmpX] != X &&
				map[tmpY][tmpX] != D && visitW[tmpY][tmpX] == INTMAX)
			{
				push(tmpX, tmpY);
				visitW[tmpY][tmpX] = visitW[t.y][t.x] + 1;
			}
		}
	}
}

void bfsG()
{
	push(sX, sY);
	visitG[sY][sX] = 1;

	while (rear != front)
	{
		point t = pop();
		for (int i = 0; i < 4; i++)
		{
			int tmpX = t.x + dx[i];
			int tmpY = t.y + dy[i];

			if (tmpX == eX && tmpY == eY)
			{
				visitG[tmpY][tmpX] = visitG[t.y][t.x] + 1;
				return;
			}

			if (map[tmpY][tmpX] != X 
				&& visitG[tmpY][tmpX] == 0
				&& visitW[tmpY][tmpX] > visitG[t.y][t.x]+1)
			{
				push(tmpX, tmpY);
				visitG[tmpY][tmpX] = visitG[t.y][t.x] + 1;
			}
		}
	}
}

void solution()
{
	bfsW();
	bfsG();
}

int main()
{
	freopen("input.txt", "r", stdin);
	inputData();
	solution();

	if (visitG[eY][eX] == 0)
		cout << "KAKTUS\n";
	else
		cout << visitG[eY][eX] - 1 << "\n";
	return 0;
}