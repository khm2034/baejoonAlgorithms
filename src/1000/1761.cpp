#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> node;
vector<vector<int>> length;
int visit[40001] = { 0, };
int depth[40001] = { 0, };
int parent[40001] = { 0, };
int pLen[40001] = { 0, };
//int tmp[40001] = { 0, };

void dfs(int here, int d)
{
	visit[here] = 1;
	depth[here] = d;

	for (int i = 0; i < node[here].size(); i++)
	{
		int there = node[here][i];
		int len = length[here][i];
		if (visit[there] == 0)
		{
			dfs(there, d + 1);
			parent[there] = here;
			pLen[there] = len;
			//length[here] = tmp[]
		}
	}
}

void inputData()
{
	int N;
	cin >> N;
	node.resize(N + 1);
	length.resize(N + 1);
	int a, b, len;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b >> len;
		node[a].push_back(b);
		node[b].push_back(a);
		length[a].push_back(len);
		length[b].push_back(len);
	}
}

void solution()
{
	dfs(1, 1);

	int M;
	int a, b;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int result = 0;
		cin >> a >> b;
		if (depth[a] < depth[b])
		{
			int tmp = a;
			a = b;
			b = tmp;
		}

		while (depth[a] != depth[b])
		{
			result += pLen[a];
			a = parent[a];
		}

		while (a != b)
		{
			result += pLen[a];
			result += pLen[b];
			a = parent[a];
			b = parent[b];
		}

		cout << result << "\n";
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	inputData();
	solution();
	return 0;
}