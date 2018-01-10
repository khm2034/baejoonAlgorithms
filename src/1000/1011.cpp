#include <iostream>
#include <math.h>

using namespace std;

struct Data
{
	unsigned int x;
	unsigned int y;
};

void input();
int solution(unsigned int x, unsigned int y);

int T;
Data* inputData;
int* outputData;

int main()
{
	input();

	for (int t = 0; t < T; t++)
	{
		outputData[t] = solution(inputData[t].x, inputData[t].y);
	}

	for (int t = 0; t < T; t++)
	{
		cout << outputData[t] << endl;
	}
	return 0;
}

void input()
{
	cin >> T;
	inputData = new Data[T];
	outputData = new int[T];

	for (int t = 0; t < T; t++)
	{
		cin >> inputData[t].x >> inputData[t].y;
	}
}

int solution(unsigned int x, unsigned int y)
{
	unsigned int distance = y - x;

	int highSpeed = sqrt(distance);
	int restDistance = distance - (highSpeed*highSpeed);
	int count = 2 * highSpeed - 1;

	int restCount = restDistance / highSpeed;
	if (restDistance%highSpeed != 0)
		restCount++;

	return count + restCount;
}