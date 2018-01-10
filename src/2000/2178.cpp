#include <iostream>
#include <vector>

using namespace std;

void input();
void solution();
void printArr();

class Point
{
public:
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

};

int sizeX;
int sizeY;

int arr[105][105];
int visit[105][105];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<Point*> stack;
int result = 1000000;
bool isFind = false;
int main()
{
	input();
	solution();
	cout << result << endl;
	return 0;
}

void input()
{
	cin >> sizeY >> sizeX;
	for (int y = 0; y <= sizeY + 1; y ++)
		for (int x = 0; x <= sizeX + 1; x++)
		{
			arr[y][x] = -1;
			visit[y][x] = 1;
		}

	for (int y = 1; y < sizeY + 1; y++)
	{
		char tmp[105];
		cin >> tmp;

		for (int x = 1; x < sizeX + 1; x++)
		{
			arr[y][x] = tmp[x - 1] - '0';
			if (arr[y][x] == 1)
				visit[y][x] = 0;
		}
	}

	visit[1][1] = 1;
	stack.push_back(new Point(1, 1));
}

void solution()
{
	int x = stack.back()->x;
	int y = stack.back()->y;

	printArr();

	if (isFind)
		return;

	if ((x == sizeX) && (y == sizeY))
	{
		if (result > visit[y][x])
			result = visit[y][x];

		if (result == (sizeX + sizeY - 1))
			isFind = true;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (visit[y + dy[i]][x + dx[i]] == 0)
		{
			if (visit[y][x]+1 == result)
				return;
			visit[y + dy[i]][x + dx[i]] = visit[y][x] + 1;
			stack.push_back(new Point(x + dx[i], y + dy[i]));
			solution();
			Point* tmp = stack[stack.size() - 1];
			delete tmp;
			stack.pop_back();
			visit[y + dy[i]][x + dx[i]] = 0;

			if (isFind)
				return;
		}
	}
	return;
}

void printArr()
{
	for (int y = 1; y < sizeY + 1; y++)
	{
		for (int x = 1; x < sizeX + 1; x++)
			cout << visit[y][x];
		cout << endl;
	}
	cout << endl;
}
