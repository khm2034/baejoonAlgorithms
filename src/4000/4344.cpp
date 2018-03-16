#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1001];
int N;
int T;
int main()
{
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		cin >> N;
		double avg = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
			avg += (double)arr[i];
		}
		avg /= N;
		sort(arr, arr + N);
		int tmp = 0;
		for (int i = 0; i < N; i++, tmp++)
			if (arr[i] > avg)
				break;
		printf("%.3lf%%\n", ((double)(N-tmp) / (double)N)*100);
	}
	return 0;
}