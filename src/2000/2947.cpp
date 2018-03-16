#include<iostream>
using namespace std;

int arr[5];
void printArr()
{
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	cout << "\n";
}
int main()
{
	for (int i = 0; i < 5; ++i)
		cin >> arr[i];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				printArr();
			}
		}
	}

	return 0;
}