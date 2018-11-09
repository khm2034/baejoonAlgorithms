#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
#include<cmath>
using namespace std;
int T, n, dis[102][102], visit[102];
vector<pair<int, int>> vec;
bool dfs(int t) {
	if (dis[t][n + 1] <= 1000) return true;
	if (t == n + 1) return true;
	for (int i = 0; i < n + 2; i++) {
		if (!visit[i] && dis[t][i] && dis[t][i] <= 1000) {
			visit[i] = true;
			if (dfs(i)) return true;
		}
	}
	return false;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		vec.clear();
		memset(dis, 0, sizeof(dis));
		memset(visit, 0, sizeof(visit));
		scanf("%d", &n);
		for (int i = 0, x, y; i < n+2; i++) {
			scanf("%d%d", &x, &y);
			vec.push_back({ x, y });
		}
		for (int i = 0; i < n+2; i++) 
			for (int j = i + 1; j < n + 2; j++) {
				int t = abs(vec[i].first - vec[j].first) + abs(vec[i].second - vec[j].second);
				dis[i][j] = dis[j][i] = t;
			}
		visit[0] = true;
		if(dfs(0)) printf("happy\n");
		else printf("sad\n");
	}
	return 0;
}