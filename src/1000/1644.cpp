#include<iostream>
#include<vector>
using namespace std;
int N, sq, le, ri, sum, cnt;
bool chk[4000001];
vector<int> p;
int main() {
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		if (chk[i]) continue;
		p.push_back(i);
		for (int j = 2; j <= N / i; j++) chk[i*j] = true;
	}
	while (1) {
		if (sum >= N) sum -= p[le++];
		else if (ri == p.size()) break;
		else sum += p[ri++];
		if (sum == N) cnt++;
	}
	printf("%d", cnt);
	return 0;
}