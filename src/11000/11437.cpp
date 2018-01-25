#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
int visit[100005] = { 0, };
int depth[100005] = { 0, };
int parent[100005] = { 0, };


void dfs(int here, int d)
{
	visit[here] = 1;
	depth[here] = d;

	for (int i = 0; i < graph[here].size(); i++)
	{
		int there = graph[here][i];

		if (visit[there] == 0)
		{
			dfs(there, d + 1);
			parent[there] = here;
		}
	}
}

void inputData()
{
	int N;
	cin >> N;
	graph.resize(N + 1);
	int a, b;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
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
		cin >> a >> b;
		if (depth[a] < depth[b])
		{
			int tmp = a;
			a = b;
			b = tmp;
		}

		while (depth[a] != depth[b])
		{
			a = parent[a];
		}

		while (a != b)
		{
			a = parent[a];
			b = parent[b];
		}

		cout << a << "\n";
	}
}

int main()
{
	inputData();
	solution();
	return 0;
}