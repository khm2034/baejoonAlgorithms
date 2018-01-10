#include <iostream>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
};

int size_x;
int size_y;
int arr[1001][1001];
int cnt_zero = 0;
int cnt_one = 0;
int cnt_not = 0;
int day = 0 ;
bool isChange;
vector<Point*> cp;
Point* tmp;

void inputData();
int solution();
void inputVector(int x, int y);
void checking();
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
				cnt_zero++;
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
		if (cnt_zero == 0)
			return day;

		checking();

		if (!isChange)
		{
			return -1;
		}

		for (int i = 0; i < cp.size(); i++) 
		{
			arr[cp[i]->y][cp[i]->x] = 1;
		}
		cp.clear();
		printArr();
		day++;
	}
}

void checking()
{
	int tmp_one = cnt_one;
	int tmp_not = cnt_not;

	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			if (arr[i][j] == 0)
			{
				if (i == 0)
				{
					if (j == 0)
					{
						if ((arr[i + 1][j] == 1) || (arr[i][j + 1] == 1))
							inputVector(j, i);
					}
					else if (j == (size_x - 1))
					{
						if ((arr[i + 1][j] == 1) || (arr[i][j - 1] == 1))
							inputVector(j, i);
					}
					else
					{
						if ((arr[i + 1][j] == 1) || (arr[i][j - 1] == 1)
							|| (arr[i][j + 1] == 1))
							inputVector(j, i);
					}
				}
				else if (i == (size_y - 1))
				{
					if (j == 0)
					{
						if ((arr[i - 1][j] == 1) || (arr[i][j + 1] == 1))
							inputVector(j, i);
					}
					else if (j == (size_x - 1))
					{
						if ((arr[i - 1][j] == 1) || (arr[i][j - 1] == 1))
							inputVector(j, i);
					}
					else
					{
						if ((arr[i - 1][j] == 1) || (arr[i][j - 1] == 1)
							|| (arr[i][j + 1] == 1))
							inputVector(j, i);
					}
				}
				else
				{
					if (j == 0)
					{
						if ((arr[i - 1][j] == 1) || (arr[i][j + 1] == 1)
							|| (arr[i + 1][j] == 1))
							inputVector(j, i);
					}
					else if (j == (size_x - 1))
					{
						if ((arr[i - 1][j] == 1) || (arr[i][j - 1] == 1)
							|| (arr[i + 1][j] == 1))
							inputVector(j, i);
					}
					else
					{
						if ((arr[i - 1][j] == 1) || (arr[i + 1][j] == 1)
							|| (arr[i][j - 1] == 1) || (arr[i][j + 1] == 1))
							inputVector(j, i);
					}
				}
			}
			else if (arr[i][j] == 1)
				tmp_one--;
			else
				tmp_not--;

			if ((size_x*size_y) == ((i*size_x) + j + 1 + tmp_one + tmp_not))
			{
				cout << "checkingOut" << endl;
				return;
			}
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
}