#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;

struct Node
{
	int from;
	int to;
	ll val;

	Node()
	{
		from = to = 0;
		val = 100000000000LL;
	}

	void insert(int _from, int _to, ll _val)
	{
		from = _from;
		to = _to;
		val = _val;
	}
};

struct Point
{
	int id;
	ll x;
	ll y;
	ll z;

	Point()
	{
		id = x = y = z = 0;
	}

	void insert(int _id, ll _x, ll _y, ll _z)
	{
		id = _id;
		x = _x;
		y = _y;
		z = _z;
	}
};

int N;
int parent[100001];
int r[100001];
Point arr[100001];
Node line_x[100001];
Node line_y[100001];
Node line_z[100001];

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
			r[y]++;
	}
}

void inputData()
{
	cin >> N;
	ll x, y, z;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y >> z;
		arr[i].insert(i + 1, x, y, z);
		make_set(i+1);
	}
}

bool comp_x(Point a, Point b)
{
	return a.x < b.x;
}
bool comp_y(Point a, Point b)
{
	return a.y < b.y;
}
bool comp_z(Point a, Point b)
{
	return a.z < b.z;
}

bool comp(Node a, Node b)
{
	return a.val < b.val;
}

ll ret= 0;

void solution()
{
	sort(arr, arr + N, comp_x);
	for (int i = 0; i < N-1; i++)
		line_x[i].insert(arr[i].id, arr[i + 1].id, abs(arr[i].x - arr[i + 1].x));
	sort(arr, arr + N, comp_y);
	for (int i = 0; i < N - 1; i++)
		line_y[i].insert(arr[i].id, arr[i + 1].id, abs(arr[i].y - arr[i + 1].y));
	sort(arr, arr + N, comp_z);
	for (int i = 0; i < N - 1; i++)
		line_z[i].insert(arr[i].id, arr[i + 1].id, abs(arr[i].z - arr[i + 1].z));

	sort(line_x, line_x + N - 1, comp);
	sort(line_y, line_y + N - 1, comp);
	sort(line_z, line_z + N - 1, comp);

	int x_idx = 0, y_idx = 0, z_idx = 0;
	for (int i = 0; i < 3*(N-1); i++)
	{
		if (line_x[x_idx].val <= line_y[y_idx].val
			&& line_x[x_idx].val <= line_z[z_idx].val)
		{
			if (find_set(line_x[x_idx].from) != find_set(line_x[x_idx].to))
			{
				union_set(line_x[x_idx].from, line_x[x_idx].to);
				ret += line_x[x_idx].val;
			}
			x_idx++;
		}
		else if (line_y[y_idx].val <= line_x[x_idx].val
			&& line_y[y_idx].val <= line_z[z_idx].val)
		{
			if (find_set(line_y[y_idx].from) != find_set(line_y[y_idx].to))
			{
				union_set(line_y[y_idx].from, line_y[y_idx].to);
				ret += line_y[y_idx].val;
			}
			y_idx++;
		}
		else
		{
			if (find_set(line_z[z_idx].from) != find_set(line_z[z_idx].to))
			{
				union_set(line_z[z_idx].from, line_z[z_idx].to);
				ret += line_z[z_idx].val;
			}
			z_idx++;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	inputData();
	solution();
	cout << ret << "\n";
	return 0;
}