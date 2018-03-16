#include<iostream>
using namespace std;
typedef long long ll;
ll N, M, K;
ll seg[1000001 * 3];

ll update(int pos, ll val, int node, int x, int y)
{
	if (pos <x || pos >y)
		return seg[node];
	if (x == y)
		return seg[node] = val;
	int mid = (x + y) / 2;
	return seg[node] = update(pos, val, node * 2, x, mid)
		+ update(pos, val, node * 2 + 1, mid + 1, y);
}

ll query(int lo, int hi, int node, int x, int y)
{
	if (x > hi || y < lo)
		return 0;
	if (lo <= x && y <= hi)
		return seg[node];
	int mid = (x + y) / 2;
	return query(lo, hi, node * 2, x, mid)
		+ query(lo, hi, node * 2 + 1, mid + 1, y);
}
int main()
{
	cin >> N >> M >> K;
	ll tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		update(i, tmp, 1, 0, N - 1);
	}
	int a, b, c;

	while (M != 0 || K != 0)
	{
		cin >> a >> b >> c;
		if (a & 1)
		{
			--M;
			update(b-1, c, 1, 0, N - 1);
		}
		else
		{
			--K;
			printf("%ld\n", query(b-1, c-1, 1, 0, N - 1));
		}
	}
	return 0;
}