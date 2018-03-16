#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

pair<int, int> arr[9];
bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}
int main()
{
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i].second);
		arr[i].first = i+1;
	}
	sort(arr, arr + 9, cmp);
	printf("%d\n%d", arr[0].second, arr[0].first);
	return 0;
}