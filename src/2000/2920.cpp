#include<iostream>
using namespace std;

int main()
{
	int arr[8];
	int type;
	for (int i = 0; i < 8; i++)
	{
		cin >> arr[i];
		if (i == 0)
		{
			if (arr[0] == 1)
				type = 1;
			else if (arr[0] == 8)
				type = 2;
			else
			{
				cout << "mixed\n";
				return 0;
			}
			continue;
		}
		else
		{
			if(type == 1 && arr[i]-arr[i-1] != 1)
			{
				cout << "mixed\n";
				return 0;
			}
			else if (type == 2 && arr[i] - arr[i - 1] != -1)
			{
				cout << "mixed\n";
				return 0;
			}
		}

	}
	if (type == 1)
		cout << "ascending\n";
	else
		cout << "descending\n";
	return 0;
}