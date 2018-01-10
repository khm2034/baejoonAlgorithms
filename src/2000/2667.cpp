#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void input();
void solution();
void findNum(int x, int y);
void result();

int map[27][27] = { 0, };
int visit[27][27] = { 0, };
//string inputVal;
int mapSize =0;
int dangiNum = 1;
int houseNum[400];
vector<int> printHouseNum;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	input();
	solution();
	result();
	return 0;
}

void input()
{
	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 27; j++)
		{
			map[i][j] = -1;
			visit[i][j] = -1;
		}

		houseNum[i] = 0;
	}

	cin >> mapSize;

	for (int i = 1; i < mapSize+1; i++)
	{
		char inputVal[27];
		cin >> inputVal;

		for (int j = 0; inputVal[j]!=NULL; j++)
		{
			map[i][j+1] = inputVal[j] - '0';
			if (map[i][j + 1] == 1)
			{
				visit[i][j + 1] = 0;
			}
		}
	}
}

void solution()
{
	for (int i = 1; i < mapSize + 1; i++)
	{
		for (int j = 1; j < mapSize + 1; j++) 
		{
			if (visit[i][j] == 0)
			{
				findNum(i, j);
				dangiNum++;
			}
		}
	}
}

void findNum(int x, int y) 
{
	visit[x][y] = dangiNum;
	houseNum[dangiNum] ++;

	for (int i = 0; i < 4; i++)
	{
		if (visit[x + dx[i]][y + dy[i]] == 0)
		{
			findNum(x + dx[i], y + dy[i]);
		}
	}
}

void result()
{
	for (int i = 1; i < dangiNum; i++)
	{
		printHouseNum.push_back(houseNum[i]);
	}

	sort(printHouseNum.begin(), printHouseNum.end());

	cout << dangiNum - 1 << endl;
	for (int i = 0; i < printHouseNum.size(); i++)
	{
		cout << printHouseNum[i] << endl;
	}
}