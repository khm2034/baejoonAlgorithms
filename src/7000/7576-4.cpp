#include <iostream>
#include <queue>
using namespace std;

void intputData();
int solution();
void checking();
void pushPoint(int x, int y);


struct Point {
	int x;
	int y;
};


int sizeX;
int sizeY;
int arr[1002][1002];
int visit[1002][1002];

queue<Point*> onePoint;
Point* tmp;
int cntZero = 0;
int cntOne = 0;
int cntEtc = 0;
int day = 0;

int dx[4] = { -1 , 1, 0 ,0 };
int dy[4] = { 0, 0, -1, 1 };


int main()
{
	intputData();
	int result = solution();
	cout << result << endl;
	return 0;
}

void intputData()
{
	cin >> sizeX >> sizeY;

	for (int y = 0; y <= sizeY + 1; y++)
		for (int x = 0; x <= sizeX + 1; x++)
		{
			arr[y][x] = -1;
			visit[y][x] = 0;
		}

	for (int y = 1; y < sizeY + 1; y++)
	{
		for (int x = 1; x < sizeX + 1; x++)
		{
			cin >> arr[y][x];

			if (arr[y][x] == 0)
			{
				cntZero++;
			}
			else if (arr[y][x] == 1)
			{
				cntOne++;
				pushPoint(x, y);
			}
		}
	}
}

int solution()
{
	while (!onePoint.empty())
	{
		checking();
		onePoint.pop();
	}


	if (cntZero != 0)
		return -1;
	else
	{
		for (int y = 1; y < sizeY + 1; y++)
			for (int x = 1; x < sizeX + 1; x++)
				if (day < visit[y][x])
					day = visit[y][x];

		return day;
	}
}
void checking()
{
	int x = onePoint.front()->x;
	int y = onePoint.front()->y;
	for (int i = 0; i < 4; i++)
	{
		if (arr[y + dy[i]][x + dx[i]] == 0)
		{
			arr[y + dy[i]][x + dx[i]] = 1;
			pushPoint(x + dx[i], y + dy[i]);
			visit[y + dy[i]][x + dx[i]] = visit[y][x] + 1;
			cntZero--;
		}
	}
}

void pushPoint(int x, int y)
{
	tmp = new Point();
	tmp->x = x;
	tmp->y = y;

	onePoint.push(tmp);
}