#include <iostream>

using namespace std;

void input();
void solution(int x, int y, int z);

int inputData[3];
int cnt = 0;
int main()
{
	input();
	solution(inputData[0], inputData[1], inputData[2]);
	cout << cnt << endl;
	return 0;
}

void input()
{
	for (int i = 0; i < 3; i++)
	{
		cin >> inputData[i];
	}
}

void solution(int x, int y, int z)
{
	if ((y - x == 1) && (z - y == 1))
		return;

	if ((y - x) > (z - y))
	{
		cnt++;
		z = x + 1;
		solution(x, z, y);
	}
	else
	{
		cnt++;
		x = z - 1;
		solution(y, x, z);
	}
}