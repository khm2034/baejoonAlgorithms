#include <iostream>
#include <queue>
using namespace std;

void intputData();
int solution();
void checking();
void pushPoint(int x, int y, int h);


struct Point {
	int x;
	int y;
	int h;
};


int sizeX;
int sizeY;
int sizeH;
int arr[102][102][102];
int visit[102][102][102];

queue<Point*> onePoint;
Point* tmp;
int cntZero = 0;
int cntOne = 0;
int cntEtc = 0;
int day = 0;

int dx[6] = { -1 , 1, 0 ,0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dh[6] = { 0, 0, 0, 0, -1, 1 };


int main()
{
	intputData();
	int result = solution();
	cout << result << endl;
	return 0;
}

void intputData()
{
	cin >> sizeX >> sizeY >> sizeH;

	for(int h= 0; h <= sizeH +1; h++)
		for (int y = 0; y <= sizeY + 1; y++)
			for (int x = 0; x <= sizeX + 1; x++)
			{
				arr[h][y][x] = -1;
				visit[h][y][x] = 0;
			}

	for(int h=1; h <sizeH + 1; h++)
		for (int y = 1; y < sizeY + 1; y++)
		{
			for (int x = 1; x < sizeX + 1; x++)
			{
				cin >> arr[h][y][x];

				if (arr[h][y][x] == 0)
				{
					cntZero++;
				}
				else if (arr[h][y][x] == 1)
				{
					cntOne++;
					pushPoint(x, y, h);
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
		for(int h=1; h< sizeH+1; h++)
			for (int y = 1; y < sizeY + 1; y++)
				for (int x = 1; x < sizeX + 1; x++)
					if (day < visit[h][y][x])
						day = visit[h][y][x];

		return day;
	}
}
void checking()
{
	int x = onePoint.front()->x;
	int y = onePoint.front()->y;
	int h = onePoint.front()->h;
	for (int i = 0; i < 6; i++)
	{
		if (arr[h + dh[i]][y + dy[i]][x + dx[i]] == 0)
		{
			arr[h + dh[i]][y + dy[i]][x + dx[i]] = 1;
			pushPoint(x + dx[i], y + dy[i], h + dh[i]);
			visit[h + dh[i]][y + dy[i]][x + dx[i]] = visit[h][y][x] + 1;
			cntZero--;
		}
	}
}

void pushPoint(int x, int y,int h)
{
	tmp = new Point();
	tmp->x = x;
	tmp->y = y;
	tmp->h = h;
	onePoint.push(tmp);
}