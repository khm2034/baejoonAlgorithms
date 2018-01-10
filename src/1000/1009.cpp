#include <iostream>

using namespace std;

struct Data
{
	int a;
	int b;
};
void input();
int solution(int a, int b);

int T;
Data* inputData;
int* outputData;

int main()
{
	input();
	for(int t = 0; t< T; t++)
	{
		outputData[t] = solution(inputData[t].a, inputData[t].b);
	}

	for (int t = 0; t< T; t++)
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
		cin >> inputData[t].a >> inputData[t].b;
	}
}

int solution(int a, int b)
{
	int result = 1;
	for (int i = 0; i < b; i++)
	{
		result *= a;
		result %= 10;
	}

	if (result == 0)
		result = 10;

	return result;
}