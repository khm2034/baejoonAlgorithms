#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> graph[1001];
bool visit[1001][2];
int N, M, V;
queue<int> q;
void bfs(){
	q.push(V);;
	visit[V][0] = true;
	printf("%d ", V);
	while (!q.empty()){
		int t = q.front(); q.pop();
		for (int n : graph[t]) {
			if (visit[n][0]) continue;
			visit[n][0] = true;
			q.push(n);
			printf("%d ", n);
		}
	}
}
void dfs(int n){
	printf("%d ", n);
	visit[n][1] = true;
	for (int t : graph[n]) {
		if (visit[t][1]) continue;
		visit[t][1] = true;
		dfs(t);
	}
}
int main(){
	scanf("%d%d%d", &N, &M, &V);
	for (int i = 0, from, to; i < M; i++){
		scanf("%d%d", &from, &to);
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());
	dfs(V);
	printf("\n");
	bfs();
	return 0;
}