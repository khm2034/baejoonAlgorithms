#include<iostream>
using namespace std;

int map[19][19];

int dx[4] = { 1, 1, 1,0 };
int dy[4] = { -1, 0, 1, 1 };

void inputData()
{
	for (int i = 0; i < 19; ++i)
		for (int j = 0; j < 19; ++j)
			cin >> map[i][j];
}

bool safe(int x, int y)
{
	return x >= 0 && x < 19 && y >= 0 && y < 19;
}

bool search(int x, int y, int color, int dir, int cnt)
{
	if (cnt == 4)
	{
		if (map[y + dy[dir]][x + dx[dir]] == color)
			return false;
		return true;
	}
	int tmpY = y + dy[dir];
	int tmpX = x + dx[dir];
	if (safe(tmpX, tmpY) && map[tmpY][tmpX] == color)
		if (search(tmpX, tmpY, color, dir, cnt + 1))
			return true;
	return false;
}

int solution()
{
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (map[i][j] != 0)
			{
				for (int k = 0; k < 4; k++)
				{
					if (safe(j - dx[k], i - dy[k]) && map[i][j] == map[i - dy[k]][j - dx[k]])
						continue;

					if (safe(j + dx[k], i + dy[k]) && map[i][j] == map[i + dy[k]][j + dx[k]])
						if (search(j + dx[k], i + dy[k], map[i][j], k, 1))
							return (i * 1000) + (j * 10) + map[i][j];
				}
			}
		}
	}
	return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	inputData();
	int ret = solution();
	if (ret == 0)
		cout << "0\n";
	else
	{
		cout << ret % 10 << "\n";
		cout << (ret / 1000)+1 << " " << ((ret / 10) % 100)+1 << "\n";
	}
	return 0;
}