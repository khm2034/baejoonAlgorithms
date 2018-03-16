#include<iostream>
#include<algorithm>
using namespace std;

struct Node
{
	int from;
	int to;
	int val;
	Node()
	{
		to = 0;
		from = 0;
		val = 0;
	}
	
	void insert(int to, int from, int val)
	{
		this->to = to;
		this->from = from;
		this->val = val;
	}
};

int N;
int M;
int ret = 0;
Node line[100001];
int parent[1001] = { 0, };
int rankk[1001] = { 0, };

void makeSet(int x)
{
	parent[x] = x;
	rankk[x] = 0;
}

int findSet(int x)
{
	if (parent[x] != x)
		parent[x] = findSet(parent[x]);

	return parent[x];
}

void unionSet(int x, int y)
{
	x = findSet(x);
	y = findSet(y);

	if (rankk[x] > rankk[y])
		parent[y] = x;
	else
	{
		parent[x] = y;
		if (rankk[x] == rankk[y])
			rankk[y]++;
	}
}
bool comp(Node x, Node y)
{
	return x.val < y.val;
}

void inputData()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		makeSet(i + 1);

	cin >> M;
	int to, from, val;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to >> val;
		line[i].insert(to, from, val);
	}
	sort(line, line + M, comp);
}

void solve()
{
	for (int i = 0; i < M; i++)
	{
		if (findSet(line[i].from) != findSet(line[i].to))
		{
			unionSet(line[i].from, line[i].to);
			ret += line[i].val;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	inputData();
	solve();
	cout << ret << endl;
	return 0;
}