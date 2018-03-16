#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Node
{
	int from;
	int to;
	ll val;
	Node()
	{
		from = to = val;
	}
	void insert(int _from, int _to, ll _val)
	{
		from = _from;
		to = _to;
		val = _val;
	}
};

int N, M;
Node line[200005];
int parent[200005];
int r[200005];

ll ret = 0;
ll sumVal = 0;

void make_set(int x)
{
	parent[x] = x;
	r[x] = 0;
}

int find_set(int x)
{
	if (x != parent[x])
		parent[x] = find_set(parent[x]);
	return parent[x];
}

void union_set(int x, int y)
{
	x = find_set(x);
	y = find_set(y);

	if (r[x] > r[y])
		parent[y] = x;
	else
	{
		parent[x] = y;
		if (r[x] == r[y])
			++r[y];
	}
}

bool comp(Node a, Node b)
{
	return a.val < b.val;
}

void inputData()
{
	for (int i = 0; i < M; ++i)
		make_set(i + 1);
	int from, to;
	ll val;
	for (int i = 0; i < N; ++i)
	{
		cin >> from >> to >> val;
		line[i].insert(from, to, val);
		sumVal += val;
	}
	sort(line, line + N, comp);
}

void solution()
{
	for (int i = 0; i < N; ++i)
	{
		if (find_set(line[i].from) != find_set(line[i].to))
		{
			union_set(line[i].from, line[i].to);
			ret += line[i].val;
		}
	}
}

void init()
{
	for (int i = 0; i < 200005; ++i)
	{
		parent[i] = r[i] = 0;
		line[i].insert(0, 0, 0);
	}
	ret = sumVal = 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	while (1)
	{
		cin >> M >> N;
		if (N == 0 && M == 0)
			break;
		init();
		inputData();
		solution();
		cout << sumVal - ret << "\n";
	}

	return 0;
}