#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
bool visit[1001][2];
int N, M, V;

int queue[1001];
int front = 0;
int rear = 0;

void push(int a)
{
	front++;
	front = front % 1001;
	queue[front] = a;
}

int pop()
{
	rear++;
	rear = rear % 1001;
	return queue[rear];
}

void BFS()
{
	push(V);
	visit[V][0] = true;
	printf("%d ", V);
	while (front != rear)
	{
		int tmp = pop();
		int size = graph[tmp].size();
		for (int i = 0; i < size; i++)
		{
			if (!visit[graph[tmp][i]][0])
			{
				push(graph[tmp][i]);
				visit[graph[tmp][i]][0] = true;
				printf("%d ", graph[tmp][i]);
			}
		}
	}
	printf("\n");
}

void DFS(int n)
{
	printf("%d ", n);
	visit[n][1] = true;
	int size = graph[n].size();
	for (int i = 0; i < size; i++)
	{
		if (!visit[graph[n][i]][1])
		{
			visit[graph[n][i]][1] = true;
			DFS(graph[n][i]);
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> V;
	int a, b;
	for (int i = 0; i <= N; i++)
		graph.push_back(vector<int>());
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());
	DFS(V);
	printf("\n");
	BFS();
	return 0;
}