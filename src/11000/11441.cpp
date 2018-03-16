#include <cstdio>
using namespace std;

int seg[400005];
int arr[100001];
int N, M;
int update(int pos, int val, int node, int x, int y)
{
	if (pos<x || pos >y)
		return seg[node];
	if (x == y)
		return seg[node] = val;
	int mid = (x + y) / 2;
	return seg[node] = update(pos, val, node * 2, x, mid) +
		update(pos, val, node * 2 + 1, mid + 1, y);
}

int query(int lo, int hi, int node, int x, int y)
{
	if (x > hi || y < lo)
		return 0;
	if (lo <= x && y <= hi)
		return seg[node];
	int mid = (x + y) / 2;
	return query(lo, hi, node * 2, x, mid) +
		query(lo, hi, node * 2 + 1, mid + 1, y);
}

void input_data()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
}

void solution()
{
	for (int i = 0; i < N; i++)
		update(i, arr[i], 1, 0, N - 1);

	scanf("%d", &M);
	int x, y;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &x, &y);
		printf("%d\n", query(x - 1, y - 1, 1, 0, N - 1));
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	input_data();
	solution();
	return 0;
}