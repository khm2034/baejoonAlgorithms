#include<iostream>
#include<algorithm>
int N, c;
std::pair<int, int> m[100001];
int main() {
	scanf("%d", &N);
	for (int i = 0,s,e; i < N; i++) {
		scanf("%d%d", &s, &e);
		m[i] = { e,s };
	}
	std::sort(m, m + N);
	for (int i = 0, n=0; i < N; i++) if (m[i].second >= n) n = m[i].first, c++;
	printf("%d", c);
	return 0;
}