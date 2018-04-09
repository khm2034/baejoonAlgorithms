#include<iostream>
#define INF 1e10
using namespace std;
typedef long long ll;
int N;
int arr[101];
int oper[4];
ll max_v = -INF;
ll min_v = INF;
void func(int n, ll val)
{
	if (n == (N-1))
	{
		if (max_v < val)
			max_v = val;
		if (min_v > val)
			min_v = val;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (oper[i])
		{
			oper[i]--;
			switch (i)
			{
			case 0:
				func(n + 1, val + arr[n + 1]);
				break;
			case 1:
				func(n + 1, val - arr[n + 1]);
				break;
			case 2:
				func(n + 1, val * arr[n + 1]);
				break;
			case 3: 
				func(n + 1, val / arr[n + 1]);
				break;
			}
			oper[i]++;
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	func(0, arr[0]);
	cout << max_v << "\n";
	cout << min_v << "\n";
	return 0;
}