#include<iostream>
#define WIDTH 6
#define HEIGHT 12
using namespace std;

int map[12][6];
char s[7];

int cnt = 1;
int result = 0;

void inputData()
{
	for (int i = 0; i < 12; i++)
	{
		cin >> s;
		for (int j = 0; j < 6; j++)
		{
			switch (s[j])
			{
			case 'R':
				map[i][j] = 1;
				break;
			case 'G':
				map[i][j] = 2;
				break;
			case 'B':
				map[i][j] = 3;
				break;
			case 'P':
				map[i][j] = 4;
				break;
			case 'Y':
				map[i][j] = 5;
				break;
			default:
				map[i][j] = 0;
				break;
			}
		}
	}
}

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool removeChk(int x, int y, int color)
{
	if (cnt >= 4)
		return true;

	for (int i = 0; i < 4; i++)
	{
		int tmpX = x + dx[i];
		int tmpY = y + dy[i];

		if (tmpX >= 0 && tmpX < WIDTH && tmpY >= 0 && tmpY < HEIGHT)
		{
			if (map[tmpY][tmpX] == color)
			{
				cnt++;
				map[y][x] = 0;
				if (removeChk(tmpX, tmpY, color))
				{
					map[y][x] = color;
					return true;
				}
				map[y][x] = color;
			}
		}
	}

	return false;
}

void removeBlock(int x, int y, int color)
{
	map[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int tmpX = x + dx[i];
		int tmpY = y + dy[i];

		if (tmpX >= 0 && tmpX < WIDTH && tmpY >= 0 && tmpY < HEIGHT)
		{
			if (map[tmpY][tmpX] == color)
			{
				removeBlock(tmpX, tmpY, color);
			}
		}
	}
}

bool chk(int x, int y)
{
	cnt = 1;
	if (removeChk(x, y, map[y][x]))
	{
		removeBlock(x, y, map[y][x]);
		return true;
	}

	return false;
}

int removeBlank(int x, int y, int* cnt, bool* findBlank)
{
	while (map[y][x])
	{
		map[y + (*cnt)][x] = map[y][x];
		map[y][x] = 0;
		y--;
	}
	*findBlank = false;
	return y + 1;
}

void drop()
{
	for (int i = 0; i < WIDTH; i++)
	{
		int blankCnt = 0;
		bool findBlank = false;
		for (int j = HEIGHT-1; j >= 0; j--)
		{
			if (!map[j][i])
			{
				blankCnt++;
				findBlank = true;
			}
			else
			{
				if (findBlank)
				{
					j = removeBlank(i, j, &blankCnt, &findBlank);
				}
			}
		}
	}
}

bool removeChain()
{
	bool doRemove = false;
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (map[i][j] != 0)
			{
				doRemove = chk(j, i) || doRemove;
			}
		}
	}

	return doRemove;
}

void solution()
{
	while (removeChain())
	{
		result++;
		drop();
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	inputData();
	solution();
	cout << result << "\n";
	return 0;
}