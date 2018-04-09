#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int N;
int arr[51];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);
	printf("%d\n", arr[0] * arr[N - 1]);
	return 0;
}