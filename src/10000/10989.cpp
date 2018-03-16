#include<iostream>
using namespace std;

int N;
int arr[10001];

int main()
{
	cin >> N;
	int tmp;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		arr[tmp]++;
	}
	
	for (int i = 0; i < 10001; ++i)
		if (arr[i] != 0)
			for (int j = 0; j < arr[i]; ++j)
				cout << i << "\n";
		
	return 0;
}