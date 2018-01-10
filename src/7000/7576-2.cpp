#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Point {
	int x;
	int y;
};

int size_x;
int size_y;
int arr[1001][1001];
int visit[1001][1001];
int cnt_zero = 0;
int cnt_one = 0;
int cnt_not = 0;
int day = 0;
bool isChange;
bool isChecking;
vector<Point*> zeroPoint;
vector<Point*> cp;
vector<int> removeIndex;
Point* tmp;

void inputData();
int solution();
void inputVector(int x, int y);
void checking(int x, int y);
void printArr();

int main()
{
	inputData();
	int result = solution();
	cout << result << endl;
}

void inputData()
{
	cin >> size_x >> size_y;

	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)
			{
				tmp = new Point();
				tmp->x = j;
				tmp->y = i;

				zeroPoint.push_back(tmp);
				cnt_zero++;
			}
			else if (arr[i][j] == 1)
				cnt_one++;
			else
				cnt_not++;
		}
	}
}

int solution()
{
	while (true)
	{
		isChange = false;
		if (zeroPoint.size() == 0)
			return day;

		int arr_size = zeroPoint.size();
		for (int i = 0; i < arr_size; i++)
		{
			isChecking = false;
			checking(zeroPoint[i]->x, zeroPoint[i]->y);
			if (isChecking)
				removeIndex.push_back(i);
		}

		while(removeIndex.size() != 0)
		{
			zeroPoint.erase(zeroPoint.begin() + removeIndex[removeIndex.size()-1]);
			removeIndex.pop_back();
		}
		removeIndex.clear();

		if (!isChange)
		{
			return -1;
		}

		for (int i = 0; i < cp.size(); i++)
		{
			arr[cp[i]->y][cp[i]->x] = 1;
			visit[cp[i]->y][cp[i]->x] = 0;
		}
		cp.clear();
		printArr();
		day++;
	}
}

void checking(int x, int y)
{
	if (y == 0)
	{
		if (x == 0)
		{
			if ((arr[y + 1][x] == 1) || (arr[y][x + 1] == 1))
				inputVector(x, y);
		}
		else if (x == (size_x - 1))
		{
			if ((arr[y + 1][x] == 1) || (arr[y][x - 1] == 1))
				inputVector(x, y);
		}
		else
		{
			if ((arr[y + 1][x] == 1) || (arr[y][x - 1] == 1)
				|| (arr[y][x + 1] == 1))
				inputVector(x, y);
		}
	}
	else if (y == (size_y - 1))
	{
		if (x == 0)
		{
			if ((arr[y - 1][x] == 1) || (arr[y][x + 1] == 1))
				inputVector(x, y);
		}
		else if (x == (size_x - 1))
		{
			if ((arr[y - 1][x] == 1) || (arr[y][x - 1] == 1))
				inputVector(x, y);
		}
		else
		{
			if ((arr[y - 1][x] == 1) || (arr[y][x - 1] == 1)
				|| (arr[y][x + 1] == 1))
				inputVector(x, y);
		}
	}
	else
	{
		if (x == 0)
		{
			if ((arr[y - 1][x] == 1) || (arr[y][x + 1] == 1)
				|| (arr[y + 1][x] == 1))
				inputVector(y, x);
		}
		else if (x == (size_x - 1))
		{
			if ((arr[y - 1][x] == 1) || (arr[y][x - 1] == 1)
				|| (arr[y + 1][x] == 1))
				inputVector(x, y);
		}
		else
		{
			if ((arr[y - 1][x] == 1) || (arr[y + 1][x] == 1)
				|| (arr[y][x - 1] == 1) || (arr[y][x + 1] == 1))
				inputVector(x, y);
		}
	}
}

void inputVector(int x, int y)
{
	tmp = new Point();
	tmp->x = x;
	tmp->y = y;

	cp.push_back(tmp);
	cnt_zero--;
	isChange = true;
	isChecking = true;
}

void printArr()
{
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}