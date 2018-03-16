#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll seg[100000 * 3];
int N, M;

ll update(int pos, ll val, int node, int x, int y)
{
	if (x > pos || y < pos)
		return seg[node];
	if (x == y)
		return seg[node] = val;

	int mid = (x + y) / 2;
	return seg[node] = update(pos, val, node * 2, x, mid)
		+ update(pos, val, node * 2 + 1, mid + 1, y);
}

ll query(int lo, int hi, int node, int x, int y)
{
	if (hi< x || y < lo)
		return 0;
	if (lo <= x && y <= hi)
		return seg[node];
	int mid = (x + y) / 2;
	return query(lo, hi, node * 2, x, mid) +
		query(lo, hi, node * 2 + 1, mid + 1, y);
}

int main()
{
	//cin >> N >> M;
	scanf("%d%d", &N, &M);
	int tmp;
	for (int i = 0; i < N; i++)
	{
		//cin >> tmp;
		scanf("%d", &tmp);
		update(i, tmp, 1, 0, N - 1);
	}

	int a, b;
	for (int i = 0; i < M; i++)
	{
		//cin >> a >> b;
		scanf("%d%d", &a, &b);
		printf("%ld\n", query(a - 1, b - 1, 1, 0, N - 1));
	}
	return 0;
}

//#include <iostream>
//#include <cstdio>
//using namespace std;
//typedef long long ll;
//ll p_sum[100001];
//int N, M;
//
//int main()
//{
//	scanf("%d%d", &N, &M);
//	ll a;
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%ld", &a);
//		p_sum[i + 1] = p_sum[i] + a;
//	}
//	int le, ri;
//	for (int i = 0; i < M; i++)
//	{
//		//cin >> le >> ri;
//		scanf("%d%d", &le, &ri);
//		printf("%ld\n", p_sum[ri] - p_sum[le-1]);
//	}
//	return 0;
//}