#include <iostream>

using namespace std;

struct arrData
{
	int data;
	int index;
};

void input();
void solution();
void swap(int x, int y);

int n;
arrData* inputData;
int* outputData;

int main()
{
	input();
	solution();
	for (int i = 0; i < n; i++)
	{
		cout << outputData[i] << " ";
	}
	return 0;
}

void input()
{
	cin >> n;
	inputData = new arrData[n];
	outputData = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> inputData[i].data;
		inputData[i].index = i;
	}
}

void solution()
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (inputData[j].data > inputData[j + 1].data)
				swap(j, j + 1);
		}
	}

	for (int i = 0; i < n; i++)
	{
		outputData[inputData[i].index] = i;
	}
}

void swap(int x, int y)
{
	arrData temp;
	temp = inputData[x];
	inputData[x] = inputData[y];
	inputData[y] = temp;
}