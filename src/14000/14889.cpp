#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define min(a,b) a>b?b:a
int N, ab[21][21], ret = 1e9;
bool visit[21];
int calc() {
	vector<int> s, l;
	int s_sum = 0, l_sum = 0;
	for (int i = 0; i < N; i++) {
		if (visit[i]) l.push_back(i);
		else s.push_back(i);
	}
	for (int i = 0; i < N/2; i++) {
		for (int j = i+1; j < N/2; j++) {
			s_sum += ab[s[i]][s[j]] + ab[s[j]][s[i]];
			l_sum += ab[l[i]][l[j]] + ab[l[j]][l[i]];
		}
	}
	return abs(s_sum - l_sum);
}
void func(int idx, int n) {
	if (n == N / 2) {
		ret = min(ret, calc());
		return;
	}
	for (int i = idx+1; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true; func(i, n + 1); visit[i] = false;
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &ab[i][j]);
	func(0, 0);
	printf("%d\n", ret);
	return 0;
}