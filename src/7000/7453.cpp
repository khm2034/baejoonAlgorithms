#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

void inputData();
void solution();

ll a[4000];
ll b[4000];
ll c[4000];
ll d[4000];
ll ab[16000000];
ll cd[16000000];

int n;
ll cnt = 0;

int main()
{
	inputData();
	solution();

	cout << cnt << endl;
	return 0;
}

void inputData()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ab[n*i + j] = a[i] + b[j];
			cd[n*i + j] = c[i] + d[j];
		}
	}
	
	sort(cd, cd + (n*n));
}

void solution()
{
	for (int i = 0; i < n*n; i++)
	{
		int hi = upper_bound(cd, cd + (n*n), -ab[i]) - cd;
		int lo = lower_bound(cd, cd + (n*n), -ab[i]) - cd;
		cnt += hi - lo;
	}
}