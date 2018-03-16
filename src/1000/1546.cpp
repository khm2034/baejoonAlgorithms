#include <iostream>
#include <cstdio>
using namespace std;

int arr[1001];
int main()
{
	int n;
	int max = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
			max = arr[i];
	}
	double ret = 0;
	for (int i = 0; i < n; i++)
		ret += (double)arr[i] / (double)max * (double)100;
	
	printf("%.2lf", ret / (double)n);
	return 0;
}