#include<iostream>
#include<algorithm>
using namespace std;

struct Point
{
	int x;
	int y;
};

Point arr[100001];
int N;

void inputData()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i].x >> arr[i].y;
}

bool comp(Point a, Point b)
{
	if (a.y == b.y)
		return a.x < b.x;

	return a.y < b.y;
}

void solution()
{
	sort(arr, arr + N, comp);
	for (int i = 0; i < N; ++i)
	{
		cout << arr[i].x << " " << arr[i].y << "\n";
	}
}

int main()
{
	inputData();
	solution();
	return 0;
}
