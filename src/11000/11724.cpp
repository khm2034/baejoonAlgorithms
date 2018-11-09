#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
vector<int> graph[1001];
bool visit[1001];
queue<int> q;
int N, M, cnt;
void bfs(int n){
	q.push(n);
	visit[n] = true;
	while (!q.empty()){
		int t = q.front(); q.pop();
		for (auto v : graph[t]){
			if (!visit[v]){
				visit[v] = true;
				q.push(v);
			}
		}
	}
}
int main(){
	scanf("%d%d", &N, &M);
	for (int i = 0, to, from; i < M; i++){
		scanf("%d%d", &from, &to);
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	for (int i = 1; i <= N; i++){
		if (!visit[i]){
			bfs(i);
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}