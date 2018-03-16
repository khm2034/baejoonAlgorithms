#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int arr[500001];
pair<int, int> cnt[8001];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}
int main()
{
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		cnt[arr[i] + 4000].first = arr[i];
		cnt[arr[i] + 4000].second++;
	}
	sort(arr, arr + N);
	sort(cnt, cnt + 8001, cmp);
	if(sum >0)
		cout << (int)((double)sum / (double)N + 0.5) << "\n";
	else
		cout << (int)((double)sum / (double)N - 0.5) << "\n";
	cout << arr[N / 2] << "\n";
	if (cnt[0].second == cnt[1].second)
		cout << cnt[1].first << "\n";
	else
		cout << cnt[0].first<< "\n";
	cout << arr[N-1] - arr[0] << "\n";
	return 0;
}