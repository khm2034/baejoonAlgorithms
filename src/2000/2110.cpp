#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

void inputData();
void solution();
ll check(ll mid);

ll n;
ll c;
ll house[200000];
ll result = 0;

int main()
{
	inputData();
	solution();

	cout << result << endl;
	return 0;
}

void inputData()
{
	cin >> n >> c;

	for (int i = 0; i < n; i++)
		cin >> house[i];

	sort(house, house + n);
}

void solution()
{
	ll right = house[n - 1] - house[0];
	ll left = 0;
	ll mid;
	ll cnt;
	while (right >= left)
	{
		mid = (right + left) / 2;

		cnt = check(mid);

		if (cnt >= c)
		{
			if (result < mid)
				result = mid;

			left = mid+1;
		}
		else
			right = mid-1;
	}
}

ll check(ll mid)
{
	ll cnt = 1;

	for (int i = 1, j=0; i < n; i++)
	{
		if ((house[i] - house[j]) >= mid)
		{
			cnt++;
			j = i;
		}
	}

	return cnt;
}