#include<iostream>
#include<cstdio>
#include <algorithm>
#define INF 1LL<<40
using namespace std;
typedef long long ll;

struct Node
{
	ll max_v;
	ll min_v;
	Node()
	{
		max_v = -INF;
		min_v = INF;
	}
};

Node seg[100000 * 3 + 1];
int N, M;
Node update(int pos, ll val, int node, int x, int y)
{
	if (pos <x || pos >y)
		return seg[node];
	if (x == y)
	{
		seg[node].max_v = seg[node].min_v = val;
		return seg[node];
	}
	int mid = (x + y) / 2;
	Node le = update(pos, val, node * 2, x, mid);
	Node ri = update(pos, val, node * 2 + 1, mid + 1, y);
	seg[node].max_v = max(le.max_v, ri.max_v);
	seg[node].min_v = min(le.min_v, ri.min_v);
	return seg[node];
}

Node query(int lo, int hi, int node, int x, int y)
{
	Node tmp;
	if (lo > y || x > hi)
		return tmp;
	if (lo <= x && hi >= y)
		return seg[node];
	int mid = (x + y) / 2;
	Node le = query(lo, hi, node * 2, x, mid);
	Node ri = query(lo, hi, node * 2 + 1, mid + 1, y);
	tmp.min_v = min(le.min_v, ri.min_v);
	tmp.max_v = max(le.max_v, ri.max_v);
	return tmp;
}

int main()
{
	scanf("%d%d", &N, &M);
	int t;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &t);
		update(i, t, 1, 0, N - 1);
	}
	int a, b;
	Node tmp;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &a, &b);
		tmp = query(a - 1, b - 1, 1, 0, N - 1);
		printf("%lld %lld\n", tmp.min_v, tmp.max_v);
	}
	return 0;
}