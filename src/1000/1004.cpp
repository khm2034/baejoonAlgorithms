#include<iostream>
#include<vector>

using namespace std;

void input();
void solution();

 class Point
{
public:
	int x;
	int y;

	Point(){}

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

class Planet :public Point
{
public:
	int r;

	Planet(int x, int y, int r) : Point(x, y)
	{
		this->r = r;
	}
};

Point* point[2];
Planet* planet[50];
int pNum;

int tmpX;
int tmpY;
int tmpR;

int tmpX2;
int tmpY2;

int cnt = 0;

int main()
{
	int testcase;

	cin >> testcase;

	for (int i = 0; i < testcase ;i++)
	{
		input();
		solution();
		cout << cnt << endl;
		cnt = 0;
	}
}

void input()
{
	cin >> tmpX >> tmpY >> tmpX2 >> tmpY2;

	point[0] = new Point(tmpX, tmpY);
	point[1] = new Point(tmpX2, tmpY2);

	cin >> pNum;
	for (int i = 0; i < pNum; i++)
	{
		cin >> tmpX >> tmpY >> tmpR;
		planet[i] = new Planet(tmpX, tmpY, tmpR);
	}
}
void solution()
{
	for (int i = 0; i < pNum; i++)
	{
		int tmpDx = (planet[i]->x - point[0]->x);
		int tmpDy = (planet[i]->y - point[0]->y);

		int d1 = (tmpDx * tmpDx) + (tmpDy * tmpDy);

		tmpDx = (planet[i]->x - point[1]->x);
		tmpDy = (planet[i]->y - point[1]->y);

		int d2 = (tmpDx * tmpDx) + (tmpDy * tmpDy);
		int r = planet[i]->r * planet[i]->r;

		if (((d1 > r) && (d2 < r)) || ((d1 < r) && (d2 > r)))
		{
			cnt++;
		}
	}
}
