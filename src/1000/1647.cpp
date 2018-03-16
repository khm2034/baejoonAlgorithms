#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
struct Node
{
	int from;
	int to;
	ll val;
	Node()
	{
		from = to = val = 0;
	}

	void insert(int from, int to, ll val)
	{
		this->from = from;
		this->to = to;
		this->val = val;
	}
};

int N, M;
Node arr[1000002];
int parent[100002];
int r[100002];

void makeSet(int x)
{
	parent[x] = x;
	r[x] = 0;
}

int findSet(int x)
{
	if (x != parent[x])
		parent[x] = findSet(parent[x]);

	return parent[x];
}

void unionSet(int x, int y)
{
	x = findSet(x);
	y = findSet(y);

	if (r[x] > r[y])
		parent[y] = x;
	else
	{
		parent[x] = y;
		if (r[x] == r[y])
			r[y]++;
	}
}

bool comp(Node x, Node y)
{
	return x.val < y.val;
}

void inputData()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		makeSet(i + 1);
	int from, to;
	ll val;
	for (int i = 0; i < M; ++i)
	{
		cin >> from >> to >> val;
		arr[i].insert(from, to, val);
	}
	sort(arr, arr + M, comp);
}
ll ret = 0;
ll maxVal = 0;
void solution()
{
	for (int i = 0; i < M; ++i)
	{
		if (findSet(arr[i].from) != findSet(arr[i].to))
		{
			unionSet(arr[i].from, arr[i].to);
			cout << arr[i].from << ", " << arr[i].to << endl;
			ret += arr[i].val;
			maxVal = arr[i].val;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	inputData();
	solution();
	cout << ret-maxVal << endl;
	return 0;
}