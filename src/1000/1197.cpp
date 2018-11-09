#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int V, E;
vector<pair<pair<int, int>, ll>> g;
ll ret;
int p[10001],  r[10001];
void make_set(int x){
	p[x] = x;
	r[x] = 0;
}
int find_set(int x){
	if (x != p[x])
		p[x] = find_set(p[x]);
	return p[x];
}
void union_set(int x, int y){
	x = find_set(x), y = find_set(y);
	if (r[x] > r[y])
		p[y] = x;
	else{
		p[x] = y;
		if (x == y)
			r[y]++;
	}
}
bool cmp(pair<pair<int, int>, ll> a, pair<pair<int, int>, ll> b)
{
	return a.second < b.second;
}
int main()
{
	scanf("%d%d", &V, &E);
	for (int i = 1; i <= V; i++)
		make_set(i);
	for (int i = 0, f, t, v; i < E; i++)
	{
		scanf("%d%d%d", &f, &t, &v);
		g.push_back({ {f,t},(ll)v });
	}
	sort(g.begin(), g.end(), cmp);
	for (auto v : g){
		if (find_set(v.first.first) != find_set(v.first.second))
		{
			ret += v.second;
			union_set(v.first.first, v.first.second);
		}
	}
	printf("%lld\n", ret);
	return 0;
}