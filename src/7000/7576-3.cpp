#include <iostream>
#include <vector>
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
int front = 0;
int last = 0;

vector<Point*> onePoint;
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

	for (int y = 1; y < sizeY+1; y++) 
	{
		for (int x = 1; x < sizeX+1; x++)
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
				last++;
			}
		}
	}
}

int solution()
{
	while(front<last)
	{
		checking();
		front++;
	}


	if (cntZero != 0)
		return -1;
	else
	{
		for (int y = 1; y < sizeY+1; y++)
			for (int x = 1; x < sizeX+1; x++)
				if (day < visit[y][x])
					day = visit[y][x];

		return day;
	}
}
void checking()
{
	int x = onePoint[front]->x;
	int y = onePoint[front]->y;
	for(int i= 0 ; i < 4; i ++)
	{
		if (arr[y + dy[i]][x + dx[i]] == 0)
		{
			arr[y + dy[i]][x + dx[i]] = 1;
			pushPoint(x + dx[i], y + dy[i]);
			visit[y + dy[i]][x + dx[i]] = visit[y][x] + 1;
			cntZero--;
			last++;
		}
	}
}

void pushPoint(int x, int y)
{
	tmp = new Point();
	tmp->x = x;
	tmp->y = y;

	onePoint.push_back(tmp);
}

/*void checking(int x, int y)
{
	if (y == 0)
	{
		if (x == 0)
		{
			visit[y + 1][x] = 1;
			if (arr[y + 1][x] == 0)
			{
				arr[y + 1][x] = 1;
				pushPoint(x, y+1);
				cntZero--;
			}

			visit[y][x + 1] = 1;
			if (arr[y][x+1] == 0)
			{
				arr[y][x+1] = 1;
				pushPoint(x+1, y);
				cntZero--;
			}
		}
		else if (x == (sizeX - 1))
		{
			visit[y + 1][x] = 1;
			if (arr[y + 1][x] == 0)
			{
				arr[y + 1][x] = 1;
				pushPoint(x, y+1);
				cntZero--;
			}

			visit[y][x - 1] = 1;
			if (arr[y][x - 1] == 0)
			{
				arr[y][x - 1] = 1;
				pushPoint(x-1, y);
				cntZero--;
			}
		}
		else
		{
			visit[y + 1][x] = 1;
			if (arr[y + 1][x] == 0)
			{
				arr[y + 1][x] = 1;
				pushPoint(x, y+1);
				cntZero--;
			}

			visit[y][x + 1] = 1;
			if (arr[y][x + 1] == 0)
			{
				arr[y][x + 1] = 1;
				pushPoint(x+1, y);
				cntZero--;
			}

			visit[y][x - 1] = 1;
			if (arr[y][x - 1] == 0)
			{
				arr[y][x - 1] = 1;
				pushPoint(x-1, y);
				cntZero--;
			}
		}
	}
	else if (y == (sizeY - 1))
	{
		if (x == 0)
		{
			visit[y - 1][x] = 1;
			if (arr[y - 1][x] == 0)
			{
				arr[y - 1][x] = 1;
				pushPoint(x, y-1);
				cntZero--;
			}

			visit[y][x + 1] = 1;
			if (arr[y][x + 1] == 0)
			{
				arr[y][x + 1] = 1;
				pushPoint(x+1, y);
				cntZero--;
			}
		}
		else if (x == (sizeX - 1))
		{
			visit[y - 1][x] = 1;
			if (arr[y - 1][x] == 0)
			{
				arr[y - 1][x] = 1;
				pushPoint(x, y-1);
				cntZero--;
			}

			visit[y][x - 1] = 1;
			if (arr[y][x - 1] == 0)
			{
				arr[y][x - 1] = 1;
				pushPoint(x-1, y);
				cntZero--;
			}
		}
		else
		{
			visit[y - 1][x] = 1;
			if (arr[y - 1][x] == 0)
			{
				arr[y - 1][x] = 1;
				pushPoint(x, y-1);
				cntZero--;
			}

			visit[y][x + 1] = 1;
			if (arr[y][x + 1] == 0)
			{
				arr[y][x + 1] = 1;
				pushPoint(x+1, y);
				cntZero--;
			}

			visit[y][x - 1] = 1;
			if (arr[y][x - 1] == 0)
			{
				arr[y][x - 1] = 1;
				pushPoint(x-1, y);
				cntZero--;
			}
		}
	}
	else
	{
		if (x == 0)
		{
			visit[y + 1][x] = 1;
			if (arr[y + 1][x] == 0)
			{
				arr[y + 1][x] = 1;
				pushPoint(x, y+1);
				cntZero--;
			}

			visit[y-1][x] = 1;
			if (arr[y-1][x] == 0)
			{
				arr[y-1][x] = 1;
				pushPoint(x, y-1);
				cntZero--;
			}

			visit[y][x + 1] = 1;
			if (arr[y][x + 1] == 0)
			{
				arr[y][x + 1] = 1;
				pushPoint(x+1, y);
				cntZero--;
			}
		}
		else if (x == (sizeX - 1))
		{
			visit[y + 1][x] = 1;
			if (arr[y + 1][x] == 0)
			{
				arr[y + 1][x] = 1;
				pushPoint(x, y+1);
				cntZero--;
			}

			visit[y - 1][x] = 1;
			if (arr[y - 1][x] == 0)
			{
				arr[y - 1][x] = 1;
				pushPoint(x, y-1);
				cntZero--;
			}

			visit[y][x - 1] = 1;
			if (arr[y][x - 1] == 0)
			{
				arr[y][x - 1] = 1;
				pushPoint(x-1, y);
				cntZero--;
			}
		}
		else
		{
			visit[y + 1][x] = 1;
			if (arr[y + 1][x] == 0)
			{
				arr[y + 1][x] = 1;
				pushPoint(x, y+1);
				cntZero--;
			}

			visit[y - 1][x] = 1;
			if (arr[y - 1][x] == 0)
			{
				arr[y - 1][x] = 1;
				pushPoint(x, y-1);
				cntZero--;
			}

			visit[y][x + 1] = 1;
			if (arr[y][x + 1] == 0)
			{
				arr[y][x + 1] = 1;
				pushPoint(x+1, y);
				cntZero--;
			}

			visit[y][x - 1] = 1;
			if (arr[y][x - 1] == 0)
			{
				arr[y][x - 1] = 1;
				pushPoint(x-1, y);
				cntZero--;
			}
		}
	}
}*/