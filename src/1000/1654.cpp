#include <iostream>

using namespace std;

typedef long long ll;
void inputData();
void solution();

ll k;
ll n;
ll arr[10001] = { 0, };
ll result = 0;
ll maxValue = 0;
int main()
{
	inputData();
	solution();

	cout << result << endl;
	return 0;
}

void inputData()
{
	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
		if (maxValue < arr[i])
			maxValue = arr[i];
	}
}

void solution()
{
	ll hi = maxValue;
	ll lo = 1;
	ll mid;
	while (hi >= lo)
	{
		mid = (hi + lo) / 2;
		ll cnt = 0;

		for (int i = 0; i < k; i++)
			cnt += (arr[i] / mid);

		if (cnt >= n)
		{
			if(result < mid)
				result = mid;
			lo = mid+1;
		}
		else
		{
			hi = mid-1;
		}
	}
}
