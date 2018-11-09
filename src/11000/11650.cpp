#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int, int>> p;
int N;
int main()
{
	scanf("%d", &N);
	for (int i = 0, x, y; i < N; i++)
	{
		scanf("%d%d", &x, &y);
		p.push_back({ x,y });
	}
	sort(p.begin(), p.end());
	for (auto v : p)
		printf("%d %d\n", v.first, v.second);
	return 0;
}